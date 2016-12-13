"""python_core, 12/13/16, Sajad Azami"""


# define Init state
class Init(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['toExplore', 'toRescue'])

    def execute(self, userdata):
        rospy.loginfo('Executing Init With Namespace :')
        rospy.loginfo(robot_namespace)
        return 'toExplore'


# define Init state
class WaitForVictim(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['victimSpotted', 'victimNotSpotted'])
        self.mutex = threading.Lock()
        self.found_recieved = False
        self.subscriber = rospy.Subscriber((robot_namespace + "/human_detection_result"), detectedobjectsMsg,
                                           self.callback)
        # self.subscriber = rospy.Subscriber("/temp", uint8, self.callback)

    def callback(self, msg):
        self.mutex.acquire()
        if msg.found == 1:
            self.found_recieved = True
        self.mutex.release()

    def execute(self, userdata):
        rospy.loginfo('Executing WaitForVictim')
        # global current_goal_status
        # listener_goal_status()
        # # 3:Goal Reached
        # while current_goal_status != 3:
        #     self.mutex.acquire()
        #     listener_goal_status()
        #     if self.found_recieved:
        #         # found recieved
        #         return 'victimSpotted'
        #     self.mutex.release()
        #     time.sleep(.1)
        # # we didn't spotted victim in the 3 sec
        # return 'victimNotSpotted'
        time.sleep(10)
        return 'victimNotSpotted'


# define Explore state
class Explore(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['goalPublished', 'goalNotPublished'])
        # rospy.Subscriber("/move_base/global_costmap/costmap", OccupancyGrid, callback_global_costmap())

    def execute(self, userdata):
        rospy.loginfo('Executing state Explore')
        # goal_list_temp = [x, y, 0, w, 0, 0, x]  # Goal Format

        current_position = get_current_position()  # current translation of robot in an array[][]
        # current_direction = get_current_direction()
        global global_costmap  # global costmap is stored here in an array[][]
        # listener_global_costmap()

        # goal_temp = get_random_goal(current_direction)  # get random goal
        goal_temp = get_random_goal(2)  # get random goal
        # TODO set goals to nearest costmap[][] = -1
        # TODO (Not Important for now) check for goal to make sure it is published using current_goal_status??

        goals_list.append(goal_temp)  # add goal to goal list(for further uses)
        move_to(goal_temp[0] + current_position[0], goal_temp[1] + current_position[1], goal_temp[2],
                goal_temp[3], goal_temp[4], goal_temp[5], goal_temp[6], )
        return 'goalPublished'


# define InitExplore state (Inner State)
class InitExplore(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['canExplore', 'cannotExplore'])

    def execute(self, userdata):
        rospy.loginfo('Executing InitExplore')
        return 'canExplore'


# define InitRescue state (Inner State)
class InitRescue(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['canRescue', 'cannotRescue'])

    def execute(self, userdata):
        rospy.loginfo('Executing state InitRescue')
        return 'canRescue'


# define Park state (Inner State)
class Park(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['parkSuccessful', 'parkFail'])
        self.mutex = threading.Lock()
        self.victim_side = 0
        self.subscriber = rospy.Subscriber((robot_namespace + "/human_detection_result"), detectedobjectsMsg,
                                           self.callback)

    def callback(self, msg):
        self.mutex.acquire()
        self.victim_side = msg.lr
        self.mutex.release()

    def execute(self, userdata):
        rospy.loginfo('Executing Park')
        current_position = get_current_position()  # current translation of robot in an array[][]
        # goal_list_temp = [x, y, 0, w, 0, 0, x]  # Goal Format

        goal_temp = [x, y, 0, w, 0, 0, x]
        goals_list.append(goal_temp)  # add goal to goal list(for further uses)
        move_to(goal_temp[0] + current_position[0], goal_temp[1] + current_position[1], goal_temp[2],
                goal_temp[3], goal_temp[4], goal_temp[5], goal_temp[6], )

        return 'parkSuccessful'


# define Shutdown state (Inner State)
class Shutdown(smach.State):
    def __init__(self):
        smach.State.__init__(self)

    def execute(self, userdata):
        rospy.loginfo('Executing Shutdown')
        return 'SHUTDOWN'


# define PassTask state (Inner State)
class PassTask(smach.State):
    def __init__(self):
        smach.State.__init__(self, outcomes=['canContinue', 'cannotContinue'])

    def execute(self, userdata):
        rospy.loginfo('Executing PassTask')
        return 'canContinue'


def main():
    rospy.init_node('behaviour')
    sm = smach.StateMachine(
        outcomes=['SHUTDOWN'])
    global robot_namespace
    if len(sys.argv) > 1:
        robot_namespace = sys.argv[1]
    with sm:
        smach.StateMachine.add('INIT', Init(),
                               transitions={'toRescue': 'INIT_RESCUE', 'toExplore': 'INIT_EXPLORE'})

        smach.StateMachine.add('INIT_RESCUE', InitRescue(),
                               transitions={'canRescue': 'PARK', 'cannotRescue': 'PASS_TASK'})

        smach.StateMachine.add('WAIT_FOR_VICTIM', WaitForVictim(),
                               transitions={'victimSpotted': 'PARK', 'victimNotSpotted': 'PASS_TASK'})

        smach.StateMachine.add('INIT_EXPLORE', InitExplore(),
                               transitions={'canExplore': 'EXPLORE', 'cannotExplore': 'SHUTDOWN'})

        smach.StateMachine.add('EXPLORE', Explore(),
                               transitions={'goalPublished': 'WAIT_FOR_VICTIM', 'goalNotPublished': 'INIT_EXPLORE'})

        smach.StateMachine.add('PARK', Park(),
                               transitions={'parkFail': 'PARK', 'parkSuccessful': 'SHUTDOWN'})

        smach.StateMachine.add('PASS_TASK', PassTask(),
                               transitions={'canContinue': 'INIT_EXPLORE', 'cannotContinue': 'SHUTDOWN'})

        sis = smach_ros.IntrospectionServer('Behavior', sm, (robot_namespace + '/SM_ROOT'))
        sis.start()

        # Execute SMACH plan
        outcome = sm.execute()

        rospy.spin()
        sis.stop()

"""
python_core, 12/8/16, Sajad Azami
Navigation API for Python
"""

import math
import random
import sys
import threading
import time

import actionlib
import roslib
import rospy
import smach
import smach_ros
import tf
import turtlesim
from actionlib_msgs.msg import GoalStatusArray
from human_detector.msg import *
from move_base_msgs.msg import *
from behaviour.msg import *
from nav_msgs.msg import OccupancyGrid
from smach_ros import ServiceState
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import Pose
from std_msgs.msg import Header
from tf import TransformListener

goals_list = []  # goals given to robot will be appended to this
current_goal_status = 0  # goal status
"""
Goal States:
PENDING=0
ACTIVE=1
PREEMPTED=2
SUCCEEDED=3
ABORTED=4
REJECTED=5
PREEMPTING=6
RECALLING=7
RECALLED=8
LOST=9
"""
global_costmap = 0  # 2d array of costmap
robot_namespace = ''
current_direction = 0  # current direction of robot explore(0-4)


# get current position of robot using tf translation
def get_current_position():
    listener = tf.TransformListener()
    rate = rospy.Rate(10.0)
    flag = True
    trans = 0
    while flag and not rospy.is_shutdown():
        try:
            (trans, rot) = listener.lookupTransform((robot_namespace + '/map'), (robot_namespace + '/base_link'),
                                                    rospy.Time(0))
            rospy.loginfo(trans)
            flag = False
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            continue
    return trans


# subscriber method callback from /move_base/status
def callback_direction_status(data):
    global current_direction
    current_direction = data.direction
    return current_direction


# subscriber method from /move_base/status
def listener_direction_status():
    rospy.Subscriber((robot_namespace + "/direction_status"), DirectionStatus, callback_direction_status)
    return


# get current position of robot using tf translation
def get_current_direction():
    listener_direction_status()


# random goal generator
# 0 for default
# 1 for NW
# 2 for NE
# 3 for SW
# 4 for SE
def get_random_goal(exp_type):
    x, y, w, z = 0, 0, 0, 0
    if exp_type == 0:
        x = random.uniform(-5.0, 5.0)
        y = random.uniform(-5.0, 5.0)
        w = 1
        z = 1
    if exp_type == 1:  # NW
        x = random.uniform(-5.0, 0)
        y = random.uniform(0, 5.0)
        w = 1
        z = 1
    if exp_type == 2:  # NE
        x = random.uniform(0.0, 5.0)
        y = random.uniform(0.0, 5.0)
        w = 1
        z = 1
    if exp_type == 3:  # SW
        x = random.uniform(-5.0, 0)
        y = random.uniform(-5.0, 0)
        w = 1
        z = 1
    if exp_type == 4:  # SE
        x = random.uniform(0, 5.0)
        y = random.uniform(-5.0, 0)
        w = 1
        z = 1

    return [x, y, 0, w, 0, 0, z]


# subscriber method callback from /move_base/status
def callback_goal_status(data):
    global current_goal_status
    current_goal_status = data.status_list[len(data.status_list) - 1].status


# subscriber method from /move_base/status
def listener_goal_status():
    rospy.Subscriber((robot_namespace + "move_base/status"), GoalStatusArray, callback_goal_status)


# subscriber method callback from /move_base/global_costmap/costmap
def callback_global_costmap(data):
    global global_costmap
    global_costmap = data.data


# subscriber method from /move_base/global_costmap/costmap
def listener_global_costmap():
    rospy.Subscriber((robot_namespace + "/move_base/global_costmap/costmap"), OccupancyGrid, callback_global_costmap)


# publishes goal on move_base/goal using SimpleActionClient
# inputs: position x, y, z, orientation w, x, y, z
def move_to(pos_x, pos_y, pos_z, ornt_w, ornt_x, ornt_y, ornt_z):
    # Simple Action Client
    sac = actionlib.SimpleActionClient((robot_namespace + 'move_base'), MoveBaseAction)

    # create goal
    goal = MoveBaseGoal()

    # set goal
    goal.target_pose.pose.position.x = pos_x
    goal.target_pose.pose.position.y = pos_y
    goal.target_pose.pose.orientation.w = ornt_w
    goal.target_pose.pose.orientation.z = ornt_z
    goal.target_pose.header.frame_id = (robot_namespace + 'odom')
    goal.target_pose.header.stamp = rospy.Time.now()

    # start listener
    sac.wait_for_server()

    # send goal
    sac.send_goal(goal)

    # finish
    # sac.wait_for_result()

    # print result
    # goal_result = sac.get_result()

    # Publisher on move_base_simple/goal
    # header = Header()
    # header.frame_id = 'map'
    # header.stamp = rospy.Time.now()
    #
    # pose = Pose()
    # pose.position.x = pos_x
    # pose.position.y = pos_y
    # pose.orientation.w = ornt_w
    # pose.orientation.z = ornt_z
    #
    # pose_stamped = PoseStamped()
    # pose_stamped.header = header
    # pose_stamped.pose = pose
    # pub = rospy.Publisher('/move_base_simple/goal', PoseStamped, queue_size=10)
    # rate = rospy.Rate(100)  # 100hz
    # pub.publish(pose_stamped)


# TODO to be completedd
# publishes goal on move_base/goal using SimpleActionClient
# inputs: position x, y, z, orientation w, x, y, z
def frontier_exploration_publish_points():
    # Simple Action Client
    sac = actionlib.SimpleActionClient((robot_namespace + 'move_base'), ExploreTaskAction)


if __name__ == '__main__':
    main()

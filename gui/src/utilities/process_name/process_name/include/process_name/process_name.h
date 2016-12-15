// C++ Headers
#include <boost/thread.hpp>

// ROS Headers
#include <ros/callback_queue.h>
#include <std_msgs/Time.h>

// Specific Headers
#include <process_name/motiontimer.h>
#include <module_name/module_name.h>
namespace process_name {
class ProcessName {
public:

	ProcessName(std::string name, ros::NodeHandle nh, ros::NodeHandle nhp);
	~ProcessName();
	// Starts running the process_name= run the modules
	void run();
	void pubTimeStart();
	void clbTimeFinish(const std_msgs::Time::ConstPtr& time);
	void spin();

private:
	ros::Time start_time_;
	ros::NodeHandle nh_;
	ros::NodeHandle nhp_;
	std::string process_name_;
	// isRunning=true if this process_name starts running
	bool is_running_;

	// process_name publishers
	ros::Publisher pub_time_start_;

	// process_name subscribers
	ros::Subscriber sub_time_finish_;

	// Modules of this process_name
	boost::shared_ptr<process_name::ModuleName> module_name_;

	//Queue
	ros::CallbackQueue modules_queue_;

};
}

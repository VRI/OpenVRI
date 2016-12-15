#include <process_name/process_name.h>
using namespace process_name;

ProcessName::ProcessName(std::string name, ros::NodeHandle nh,
		ros::NodeHandle nhp) :
		process_name_(name), nh_(nh), nhp_(nhp) {
	// be careful all modules must have the same nodeHandle
	// all topics must have unique name because all of them call process_name_name +
	is_running_ = false;

	// Setting callback queue
	nh_.setCallbackQueue(&modules_queue_);
	nhp_.setCallbackQueue(&modules_queue_);

	// Declare advertises
	pub_time_start_ = nh_.advertise<std_msgs::Time>(process_name_ + "/time1",
			1);

	// Declare subscribers
	sub_time_finish_ = nh_.subscribe(process_name_ + "/time2", 1,
			&ProcessName::clbTimeFinish, this);

	// Initialize variables and interfaces
	module_name_ = boost::make_shared<process_name::ModuleName>("module_name",
			process_name_, nh_, nhp_);
}

ProcessName::~ProcessName() {
}

void ProcessName::run() {
	ROS_INFO("ProcessName run\n");
	module_name_->run();
}

void ProcessName::pubTimeStart() {
	is_running_ = true;

	std_msgs::Time::Ptr time = boost::make_shared<std_msgs::Time>();
	start_time_ = ros::Time::now();
	time->data = start_time_;
	pub_time_start_.publish(time);
}

void ProcessName::clbTimeFinish(const std_msgs::Time::ConstPtr& time) {
	is_running_ = false;
}

void ProcessName::spin() {
	ros::Duration(1).sleep();
	MotionTimer timer(0.01);
	ros::Duration execTime;

	while (ros::ok()) {
		uint64_t expirations = timer.sleep();

		if (expirations > 1) {
			if (expirations > 2) {
				ROS_WARN("Missed %lu timer cycles, exec took %lf secs",
						expirations - 1, execTime.toSec());

			} else
				ROS_INFO_THROTTLE(0.01,
						"Missed a timer cycle, exec took %lf secs",
						execTime.toSec());
		}
		ros::Time start = ros::Time::now();

		pubTimeStart();

		while (is_running_ && ros::ok()) {
			modules_queue_.callAvailable(ros::WallDuration(0));
			ros::spinOnce();
		}

		execTime = (ros::Time::now() - start);

	}
}

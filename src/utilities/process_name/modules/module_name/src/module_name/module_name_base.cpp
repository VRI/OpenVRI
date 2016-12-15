#include <module_name/module_name_base.h>

using namespace process_name;

ModuleNameBase::ModuleNameBase() {
}

void ModuleNameBase::setPublishers() {
	ROS_INFO("Set Publishers");
	pub_time_ = nhp_.advertise < std_msgs::Time> (node_name_ + "/time2", 1);
	pub_int_ = nhp_.advertise < std_msgs::Int64> (node_name_ + "/int", 1);
}

void ModuleNameBase::setSubscribers() {
	ROS_INFO("Set Subscribers");
	sub_time_ = nhp_.subscribe(node_name_ + "/time1", 1, &ModuleNameBase::clbTime, this);
}

void ModuleNameBase::setSync() {
	m_sub_point1_.subscribe(nh_, node_name_ + "/m_point1", 1);
	m_sub_point2_.subscribe(nh_, node_name_ + "/m_point2", 1);
	sync_int_ = boost::make_shared< message_filters::TimeSynchronizer<geometry_msgs::PointStamped,geometry_msgs::PointStamped> >(
					m_sub_point1_,m_sub_point2_, 1);
	sync_int_->registerCallback(boost::bind(&ModuleNameBase::clbSync, this, _1, _2));
}

void ModuleNameBase::clbSync(const geometry_msgs::PointStampedConstPtr& point1, const geometry_msgs::PointStampedConstPtr& point2) {
	// be carefull all stamp must be the same, so fill stamp of outputs from stamp of input. this is nessecary for time synchronize
	TEST_CALLBACK_TIME(CALLBACK_NAME)
	required_point1 = point1;
	required_point2 = point2;
	std_msgs::Int64::Ptr provided_int = boost::make_shared<std_msgs::Int64>();

	update(provided_int);
	pub_int_.publish(provided_int);
    TEST_END(CALLBACK_NAME)
}

void ModuleNameBase::clbTime(const std_msgs::Time::ConstPtr& time) {

	TEST_CALLBACK_TIME(CALLBACK_NAME)
      uses_time = time;
      std_msgs::Time::Ptr provided_time = boost::make_shared<std_msgs::Time>();
      update(provided_time);
     pub_time_.publish(provided_time);
    TEST_END(CALLBACK_NAME)
}

void ModuleNameBase::run() {
  setPublishers();
  setSubscribers();
  setSync();
}

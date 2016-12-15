#include <module_name/module_name_base.h>

using namespace process_name;

ModuleNameBase::ModuleNameBase() {
}

void ModuleNameBase::setPublishers() {
	ROS_INFO("Set Publishers");
	time_publisher_ = nhp_.advertise < std_msgs::Time> (node_name_ + "/time2", 1);
	int_publisher_ = nhp_.advertise < std_msgs::Int64> (node_name_ + "/int", 1);
}

void ModuleNameBase::setSubscribers() {
	ROS_INFO("Set Subscribers");
	time_subscriber_ = nhp_.subscribe(node_name_ + "/time1", 1, &ModuleNameBase::timeCallback, this);
}

void ModuleNameBase::setSync() {
	m_point_subscriber1_.subscribe(nh_, node_name_ + "/m_point1", 1);
	m_point_subscriber2_.subscribe(nh_, node_name_ + "/m_point2", 1);
	sync_int_ = boost::shared_ptr< message_filters::TimeSynchronizer<geometry_msgs::PointStamped,geometry_msgs::PointStamped> >
	                (new message_filters::TimeSynchronizer<
					geometry_msgs::PointStamped, geometry_msgs::PointStamped>(
					m_point_subscriber1_, m_point_subscriber2_, 1));
	sync_int_->registerCallback(boost::bind(&ModuleNameBase::syncCallback, this, _1, _2));
}

void ModuleNameBase::syncCallback(const geometry_msgs::PointStampedConstPtr& point1, const geometry_msgs::PointStampedConstPtr& point2) {

	TEST_CALLBACK_TIME(CALLBACK_NAME)
	 std_msgs::Int64::Ptr provided_int = boost::make_shared<std_msgs::Int64>();
	 update(provided_int);
	 int_publisher_.publish(*provided_int);
    TEST_END(CALLBACK_NAME)
}

void ModuleNameBase::timeCallback(const std_msgs::Time::ConstPtr& time) {

	TEST_CALLBACK_TIME(CALLBACK_NAME)
      theUsesTime = *time;
      std_msgs::Time::Ptr provided_time = boost::make_shared<std_msgs::Time>();
      update(provided_time);
      time_publisher_.publish(provided_time);
    TEST_END(CALLBACK_NAME)
}

void ModuleNameBase::run() {
  setPublishers();
  setSubscribers();
  setSync();
}

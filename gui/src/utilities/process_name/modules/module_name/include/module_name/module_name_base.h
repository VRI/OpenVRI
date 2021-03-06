#ifndef MODULENAMEBASE_H
#define MODULENAMEBASE_H

// C++ Headers
#include <string>

// ROS Headers
#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_msgs/String.h>
#include <std_msgs/Time.h>
#include <geometry_msgs/PointStamped.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

// Specific Headers
#include <module_name/module_test.h>


namespace process_name{

class ModuleNameBase {
public:
	// default constructor
	ModuleNameBase();
	// Sets the publishers, subscribers, message filters, ...
	void run();

protected:

    // Required: are message types that are which this module required to process
	geometry_msgs::PointStampedConstPtr required_point1;
	geometry_msgs::PointStampedConstPtr required_point2;

	// Uses: are message types for which subscriber is defined
	std_msgs::TimeConstPtr uses_time;

	// Provided: are message types that are provided by modules to others


	ros::NodeHandle nh_;
	ros::NodeHandle nhp_;
	std::string node_name_;
	std::string module_name_;

	// update methods are called in respond to changing state of specified message
	virtual void update(std_msgs::Int64::Ptr& i)=0; // define pure virtual or implement it in base class.
	virtual void update(std_msgs::Time::Ptr& time)=0;

private:
	// Message Filter, for synchronous message callbacks
	message_filters::Subscriber<geometry_msgs::PointStamped> m_sub_point1_;
	message_filters::Subscriber<geometry_msgs::PointStamped> m_sub_point2_;
	boost::shared_ptr<message_filters::TimeSynchronizer<geometry_msgs::PointStamped,geometry_msgs::PointStamped> > sync_int_;

	// Define Publishers
	ros::Publisher pub_time_;
	ros::Publisher pub_int_;

	// Define Subscribers
	ros::Subscriber sub_time_;

	// Callbacks
	void clbTime(const std_msgs::Time::ConstPtr& time);

    // Message Filter Callbacks
	void clbSync(const geometry_msgs::PointStampedConstPtr&,const geometry_msgs::PointStampedConstPtr&); // name can include the output e.g. joint_data

	// Publishers, Subscribers and Message Filter Setters
	void setSubscribers();
	void setPublishers();
	void setSync();

};

}
#endif

#ifndef MODULE_TEST_H
#define MODULE_TEST_H

// C++ Headers
#include <string>

// ROS Headers
#include <ros/ros.h>

// Define TEST_MODULES Section
#define CALLBACK_NAME  __FUNCTION__ // Returns te name of function executing now
#define TEST_MODULES_
// This Test returns execute time of a module
#ifdef TEST_MODULES
	#define TEST_CALLBACK_TIME(CallbackName)  \
			double startTime= ros::Time::now().toSec(); \
			ROS_INFO("%s from Module %s",CallbackName, module_name_.c_str()); \

	#define TEST_END(CallbackName) \
		double diff = ros::Time::now().toSec()-startTime; \
		ROS_INFO("Callback Duration %s from module %s = %f \n",CallbackName ,module_name_.c_str(), diff);\

#else

	#define TEST_CALLBACK_TIME(CallbackName)
	#define TEST_END(CallbackName)

#endif


#endif

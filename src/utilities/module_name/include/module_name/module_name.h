#ifndef MODULENAME_H
#define MODULENAME_H

// Specific Headers
#include <module_name/module_name_base.h>
namespace process_name{

class ModuleName: public ModuleNameBase {
public:
	explicit ModuleName(std::string name, std::string node_name,
			ros::NodeHandle nh, ros::NodeHandle nhp);
	void update(std_msgs::Int64::Ptr& i);
	void update(std_msgs::Time::Ptr& time);
};

}
#endif

#include <module_name/module_name.h>

using namespace process_name;

ModuleName::ModuleName(std::string name, std::string node_name, ros::NodeHandle nh, ros::NodeHandle nhp) : ModuleNameBase() {
	module_name_ = name;
	node_name_ = node_name;
	nh_ = nh;
	nhp_ = nhp;
}
;
void ModuleName::update(std_msgs::Time::Ptr& time) {
	*time = theUsesTime;
}

void ModuleName::update(std_msgs::Int64::Ptr& i) {
	*i = theRequiredInt;
}

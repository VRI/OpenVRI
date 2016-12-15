#ifndef MODULENAME_H
#define MODULENAME_H

// Specific Headers
#include <module_name/module_name_base.h>
#include <config_server/parameter.h>

namespace process_name{

struct Parameters
{
	Parameters()
	:g1_p1("module_name/group1/param1",0,0.001,2.0,0.09)
	,g1_p2("module_name/group1/param2",0,0.001,2.0,0.09)
	,g2_p1("module_name/group2/param1",0,0.001,2.0,0.09)
	,g2_p2("module_name/group2/param2",0,0.001,2.0,0.09){};

	config_server::Parameter<float> g1_p1;
	config_server::Parameter<float> g1_p2;
	config_server::Parameter<float> g2_p1;
	config_server::Parameter<float> g2_p2;

};

class ModuleName: public ModuleNameBase {
public:
	explicit ModuleName(std::string name, std::string node_name,
			ros::NodeHandle nh, ros::NodeHandle nhp);
	void update(std_msgs::Int64::Ptr& i);
	void update(std_msgs::Time::Ptr& time);
	void clbChangeParam();
private:
	//boost::shared_ptr<Parameters> m_param;
	Parameters *m_param;
	double g1_p1_;
	double g1_p2_;
	double g2_p1_;
	double g2_p2_;
};

}
#endif

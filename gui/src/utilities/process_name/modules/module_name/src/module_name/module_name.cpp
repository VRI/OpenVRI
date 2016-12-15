#include <module_name/module_name.h>

using namespace process_name;

void change(float v)
{
	ROS_INFO("Parameter was changed externally\n");

}
ModuleName::ModuleName(std::string name, std::string node_name, ros::NodeHandle nh, ros::NodeHandle nhp) : ModuleNameBase() {
	module_name_ = name;
	node_name_ = node_name;
	nh_ = nh;
	nhp_ = nhp;

	//m_param = boost::make_shared<Parameters>();
	m_param = new Parameters();
	m_param->g1_p1.setCallback(boost::bind(&ModuleName::clbChangeParam,this));
	m_param->g1_p2.setCallback(boost::bind(&ModuleName::clbChangeParam,this));
	m_param->g2_p1.setCallback(boost::bind(&ModuleName::clbChangeParam,this));
	m_param->g2_p2.setCallback(boost::bind(&ModuleName::clbChangeParam,this));

}
;

void ModuleName::clbChangeParam()
{
	g1_p1_ = m_param->g1_p1();
	g1_p2_ = m_param->g1_p2();
	g2_p1_ = m_param->g2_p1();
	g2_p2_ = m_param->g2_p2();
	ROS_INFO("Parameter was changed = %f %f %f %f\n",g1_p1_,g1_p2_,g2_p1_,g2_p2_);
}
void ModuleName::update(std_msgs::Time::Ptr& time) {
	// time = uses_time;
}

void ModuleName::update(std_msgs::Int64::Ptr& i) {
}

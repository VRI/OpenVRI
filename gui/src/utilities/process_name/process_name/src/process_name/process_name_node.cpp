#include <process_name/process_name.h>
using namespace process_name;

int main(int argc,char** argv)
{
	ros::init(argc,argv,"process_name");
	boost::shared_ptr<ProcessName> process_name = boost::make_shared<ProcessName>(ros::this_node::getName(),ros::NodeHandle(),ros::NodeHandle("~"));

	// Starts runnig the process_name
	process_name->run();

	// Starts process_nameing callbacks
	process_name->spin();

	return 0;
}

#include <server_debug/server_debug.h>

ServerDebug *ServerDebug::MInstance = 0;

ServerDebug *ServerDebug::Instance() {

	if (!MInstance)
		MInstance = new ServerDebug();
	return MInstance;
}

ServerDebug::ServerDebug(){

	atexit (&CleanUp);

	srv_add_debugString_ = ros::NodeHandle().advertiseService("ServerDebug/add",
			&ServerDebug::addDebugString, this);
	srv_del_debugString_ = ros::NodeHandle().advertiseService("ServerDebug/del",
			&ServerDebug::delDebugString, this);
	debug_string_prefix_="debug/";
}

void ServerDebug::CleanUp() {
	delete MInstance;
	MInstance = 0;
}

ServerDebug::~ServerDebug()
{
     for(int itr=0;config_params_debug_.size();++itr) {
		 delete(config_params_debug_[itr]);
	 }
}

bool ServerDebug::addDebugString(server_debug::ServerDebugAdd::Request &req,
		server_debug::ServerDebugAdd::Response &res) {
	std::string debug_str(req.debugString);
	addDebugString(debug_str);

}

bool ServerDebug::delDebugString(server_debug::ServerDebugDel::Request &req,
		server_debug::ServerDebugAdd::Response &res) {
	std::string debug_str(req.debugString);
	delDebugString(debug_str);
}

void ServerDebug::addDebugConfigParameter(std::string debug_parameter){

	// declare debugParameter with added "debug" in front of str ofcource after checking redundancy
	std::string debug_parameter_edited=debug_parameter;

	//check if this parameter is redundant
		bool is_redundant=false;

		for (int itr=0;itr<config_params_debug_.size();++itr){
                      std::string extracted_debug_string=extractDebugString(config_params_debug_[itr]->getName());
			if (extracted_debug_string.compare(debug_parameter_edited)==0) {
					  is_redundant=true;
					  break;
			}
		}
		if(!is_redundant){
                        // declare debugParameter with added "debug" in front of str
                        std::string debug_parameter_edited=debug_string_prefix_+debug_parameter;

			// for every DEBUG(debugString) if the debugString is not added to depag_parts too, add it to config server
			// add defined config_server to config_params_debug

			config_params_debug_.push_back(new config_server::Parameter<bool>(debug_parameter_edited, false));

			for (int itr=0;itr<config_params_debug_.size();++itr) {
				config_params_debug_[itr]->setCallback(boost::bind(&ServerDebug::clbChangeParams, this));
			}
	   }
}

bool ServerDebug::checkDebugString(std::string debug_string) {

	if (debug_parts_.find(debug_string) != debug_parts_.end()) {
		return true;
	}
	return false;
}

void ServerDebug::addDebugString(std::string debug_string) {

	if (debug_parts_.find(debug_string) == debug_parts_.end()) {
		debug_parts_.insert(debug_string);
	}
}

void ServerDebug::delDebugString(std::string debug_string) {

	std::set<std::string>::iterator itr = debug_parts_.find(debug_string);
	if (itr != debug_parts_.end()) {
		debug_parts_.erase(itr);
	}
}

void ServerDebug::clbChangeParams() {

//	ROS_INFO("Parameters Changes");
//      ROS_INFO("debug_parts = %d and config_params = %d ",debug_parts_.size(),config_params_debug_.size());

	for (int itr=0;itr<config_params_debug_.size();++itr) {
		std::string extracted_debug_string=extractDebugString(config_params_debug_[itr]->getName());
			if (config_params_debug_[itr]->get()){
				addDebugString(extracted_debug_string);
				//ROS_INFO("Parameter %s added to list",extracted_debug_string.c_str());
			}
			else {
				delDebugString(extracted_debug_string);
				//ROS_INFO("Parameter %s deleted from list",extracted_debug_string.c_str());
			}
		}
	}

std::string ServerDebug::extractDebugString(const std::string debug_config_parameter){

	// because config_server adds process_name to begin of config parameters
	int pos=debug_config_parameter.find(debug_string_prefix_);
	std::string tmp=debug_config_parameter.substr (pos);
	pos=tmp.find("/");
	// ignore "/"
    return tmp.substr (pos+1);
}

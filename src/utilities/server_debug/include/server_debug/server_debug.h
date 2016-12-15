#ifndef SERVER_DEBUG_H
#define SERVER_DEBUG_H_

#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <set>
#include <server_debug/ServerDebugAdd.h>
#include <server_debug/ServerDebugDel.h>
#include <config_server/parameter.h>

#define DEBUG_MODE

#ifdef DEBUG_MODE
  #define DEBUG(debugString)  if(ServerDebug::Instance()->checkDebugString(debugString)==true) {
  #define DEBUG_END() }
  #define DEBUG_ADD(debugParameter)  ServerDebug::Instance()->addDebugConfigParameter(debugParameter);
#else
  #define DEBUG(debugString) if(false) {
  #define DEBUG_END() }
  #define DEBUG_ADD
#endif


class ServerDebug
{
public:
         bool checkDebugString(std::string debugString);

         // add DEBUG_ADD parameter to config_server parameter
         void addDebugConfigParameter(std::string debugParameter);

         static ServerDebug *Instance();
private:
	 ServerDebug();
         //not copyable
         static void CleanUp();

         ~ServerDebug();
         // Services for add and delete debug strings
         bool addDebugString(server_debug::ServerDebugAdd::Request &req, server_debug::ServerDebugAdd::Response &res);
         bool delDebugString(server_debug::ServerDebugDel::Request &req, server_debug::ServerDebugAdd::Response &res);

         // private functions for add, delete debug parts

         void addDebugString(std::string debugString);
         void delDebugString(std::string debugString);

         // callback for checking add/del parameters
         void clbChangeParams();

         std::string extractDebugString(const std::string debug_config_parameter);

         std::set<std::string> debug_parts_;
	     static ServerDebug *MInstance ;
         ros::ServiceServer srv_add_debugString_;
         ros::ServiceServer srv_del_debugString_;
         std::vector< config_server::Parameter<bool> * > config_params_debug_;
         // define constant str that adds front of debugStrings - prefix
         std::string debug_string_prefix_;
};

#endif

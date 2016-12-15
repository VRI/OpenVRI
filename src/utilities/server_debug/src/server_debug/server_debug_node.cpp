#include <server_debug/server_debug.h>

int main(int argc, char** argv)
{
  ros::init(argc,argv,"Server_Debug_Node");
   
  ServerDebug::Instance();

  ros::spin();

  return 0;

}

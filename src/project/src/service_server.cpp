#include "ros/ros.h"
#include "project/CheckWeather.h"

bool checkWeather(project::CheckWeather::Request &req,
                      project::CheckWeather::Response &res)
{

  if(req.gps == "41.40338,2.17403")
  {
    res.temperature = 22;
  }
  else if(req.gps == "52.40226,4.26252")
  {
    res.temperature = 18;
  }
  else if(req.gps == "11.11111,2.22222")
  {
    res.temperature = 20;
  }
  else
  {
    return false;
  }

  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server_node");

  ros::NodeHandle node_handle;

  ros::ServiceServer service = node_handle.advertiseService("check_weather", checkWeather);

  ROS_INFO("Weather Server Running...");

  ros::spin();

  return 0;
}

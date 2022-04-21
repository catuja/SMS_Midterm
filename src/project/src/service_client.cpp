#include "ros/ros.h"
#include "project/CheckWeather.h"
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client_node");

  ros::NodeHandle node_handle;

  ros::ServiceClient client = node_handle.serviceClient<project::CheckWeather>("check_weather");

  project::CheckWeather srv;

  std::string input_gps;

  std::cout << "Type exit to quit" << std::endl;

  while (ros::ok())
  {
    std::cout << "Enter GPS value: ";
    std::cin >> input_gps;

    srv.request.gps = input_gps;

    if (input_gps == "exit")
    {
      ROS_INFO("Exiting Application...");
      return 0;
    }
    if (client.call(srv))
    {
      int resp;
      resp = srv.response.temperature;

      std::cout << "The temperature is " << resp << " degrees" << std::endl;
    }
    else
    {
      ROS_ERROR("Service Call Failed");
      return 1;
    }

    std::cin.clear();
  }
}
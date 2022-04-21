#include "std_msgs/Float32.h"
#include "std_msgs/String.h"
#include "ros/ros.h"

float SPEED_LIMIT;

ros::Publisher platenumber_pub;

void subCallback(const std_msgs::Float32::ConstPtr& speed)
{
  ros::NodeHandle callback_node_handle;

  if (callback_node_handle.getParam("speed_limit", SPEED_LIMIT))
   {
      if (SPEED_LIMIT < speed->data)
      {
        std_msgs::String msg;
        msg.data = "ABC1234";
        platenumber_pub.publish(msg);
      }
   }
   else 
   {
      ROS_WARN("No Value set for speed_limit server parameter.");
   }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");

  ros::NodeHandle node_handle;

  platenumber_pub = node_handle.advertise<std_msgs::String>("platenumber", 10);

  ros::Subscriber speed_sub = node_handle.subscribe("speed", 10, subCallback);

  ros::spin();

  return 0;
}
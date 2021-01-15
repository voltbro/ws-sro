#include <ros.h>
#include <std_msgs/String.h>

class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial1, 115200){};
};
ros::NodeHandle_<NewHardware>  nh;

std_msgs::String str_msg;
ros::Publisher ros_tester("arduino_connect_tester", &str_msg);

char hello[13] = "Test";

void setup()
{
  nh.initNode();
  nh.advertise(ros_tester);
}

void loop()
{
  str_msg.data = hello;
  ros_tester.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}

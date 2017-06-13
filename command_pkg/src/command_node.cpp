#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main (int argc, char** argv)
{

	// Init node
	ros::init(argc, argv, "command");
	ros::NodeHandle node;
	
	// Init publisher
	ros::Publisher command_publisher = node.advertise<geometry_msgs::Twist>("/vehicle_command", 1, true);
	
	ros::Rate rate(30.0);	// Set a minimum time for a cycle
	while (node.ok())
	{
		ros::spinOnce();
		
		double vehicle_speed;
		double vehicle_angular_speed;
		
		// Vehicle command
		vehicle_speed = 3.;
		vehicle_angular_speed = 0.1;
				
		// Publish command
		geometry_msgs::Twist command_message;	 			// Create the message
		command_message.linear.x = vehicle_speed; 					// Fill the message with speed
		//command_message.linear.y = vehicle_angular_speed;
		command_message.point.z = vehicle_angular_speed;		// Fill the message with angular speed
		command_publisher.publish(command_message);	// Publish the message
		
		rate.sleep();	// Wait for next cycle
	}
}

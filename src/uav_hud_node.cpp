/*
 * uav_hud_node.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#include "ros/ros.h"

#include "ImageConverter.h"

int main(int argc, char **argv) {
  ROS_INFO("Node started");
  ros::init(argc, argv, "image_converter");
  uav_hud::ImageConverter ic;
  ros::spin();
}

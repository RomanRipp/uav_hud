/*
 * uav_hud_node.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#include "uav_hud/ros_topics.h"
#include "uav_hud/ImageConverter.h"

#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "image_converter");
  uav_hud::ImageConverter ic;
  ros::spin();
}

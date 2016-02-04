/*
 * uav_hud_node.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#include "ros/ros.h"
#include <QtGui/QGuiApplication>

#include "ImageConverter.h"

int main(int argc, char **argv) {
  ROS_INFO("Node starting");

  ros::init(argc, argv, "image_converter");

  QGuiApplication app(argc, argv);
  uav_hud::ImageConverter imageConverter;

  app.exec();
  ros::spin();
}

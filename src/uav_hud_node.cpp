/*
 * uav_hud_node.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#include "ros/ros.h"
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>

#include "ImageConverter.h"

int main(int argc, char **argv) {
  ROS_INFO("Node started");

  QGuiApplication app(argc, argv);
  QFontDatabase::addApplicationFont(":/fonts/DejaVuSans.ttf");
  app.setFont(QFont("DejaVu Sans"));
  QQmlApplicationEngine engine(QUrl("/home/robot/catkin_ws/src/uav_hud/qml/dashboard.qml"));
  app.exec();

  ros::init(argc, argv, "image_converter");
  uav_hud::ImageConverter ic;
  ros::spin();
}

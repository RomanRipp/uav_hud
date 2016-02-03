/*
 * uav_hud_node.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#include "ros/ros.h"
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>


#include "ImageConverter.h"

int main(int argc, char **argv) {
  ROS_INFO("Node starting");

  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/qml/hud.qml")));

  QQuickWindow* window = qobject_cast<QQuickWindow*>(engine.rootObjects().at(0));
  window->show();

  window->setWidth(640);
  window->setHeight(368);

//  ros::init(argc, argv, "image_converter");
//  uav_hud::ImageConverter ic;
//  ros::spin();

  return app.exec();
}

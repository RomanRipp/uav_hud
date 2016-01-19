/*
 * BatteryLevel.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include "BatteryLevel.h"

#include <opencv2/imgproc/imgproc.hpp>
#include "ros/ros.h"

namespace uav_hud {

BatteryLevel::BatteryLevel() {
	// TODO Auto-generated constructor stub

}

BatteryLevel::~BatteryLevel() {
	// TODO Auto-generated destructor stub
}

void BatteryLevel::Update(const std_msgs::Int32& level) {
	ROS_INFO("Battery level:  x=%ld", level);
}

void BatteryLevel::Draw(const cv_bridge::CvImagePtr& cv_ptr) {
	// Draw an example circle on the video stream
	if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
	{
		cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(0, 255, 0));
	}
}

void BatteryLevel::Erase() {

}

}

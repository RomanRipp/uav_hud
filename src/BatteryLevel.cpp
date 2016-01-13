/*
 * BatteryLevel.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include <opencv2/imgproc/imgproc.hpp>

#include "BatteryLevel.h"

namespace uav_hud {

BatteryLevel::BatteryLevel() {
	// TODO Auto-generated constructor stub

}

BatteryLevel::~BatteryLevel() {
	// TODO Auto-generated destructor stub
}

void BatteryLevel::Draw(const cv_bridge::CvImagePtr& cv_ptr) {
	// Draw an example circle on the video stream
	if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
		cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255, 0, 0));
}

void BatteryLevel::Erase() {

}

}

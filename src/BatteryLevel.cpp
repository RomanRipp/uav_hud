/*
 * BatteryLevel.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include <string>
#include "ros/ros.h"
#include <opencv2/imgproc/imgproc.hpp>

#include "BatteryLevel.h"
#include "UISettings.h"

namespace uav_hud {

BatteryLevel::BatteryLevel() : BaseGraphicElement(),
		m_batteryLevel(0)
{

}

void BatteryLevel::Update(const bebop_msgs::CommonCommonStateBatteryStateChanged& level) {
	ROS_INFO("Battery level:  x=%d", level.percent);
	m_batteryLevel = level.percent;
	m_IsUpdated = true;
}

void BatteryLevel::Draw(const cv_bridge::CvImagePtr& cv_ptr) {
	// Draw an example circle on the video stream
	if (m_IsUpdated) {
		std::string text = "BAT: ";
		text += std::to_string(m_batteryLevel);
		text += "%";
		auto color = m_batteryLevel < 10 ? defaults::ERROR_COLOR : defaults::COLOR;
		cv::Point textOrg(10, 130);




		cv::putText(cv_ptr->image,
				text,
				textOrg,
				defaults::FONT_FACE,
				defaults::FONT_SCALE,
				color,
				defaults::THICKNESS, 8);
	}
}
}

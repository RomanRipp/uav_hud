/*
 * BatteryLevel.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include "BatteryLevel.h"
#include "UISettings.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include "ros/ros.h"

namespace uav_hud {

static cv::Point GetTextPosition(){
	return cv::Point(defaults::MARGIN, 2*defaults::MARGIN);
}

BatteryLevel::BatteryLevel() : BaseGraphicElement(),
		m_batteryLevel(0), m_text("BAT: ")
{

}

void BatteryLevel::Update(const bebop_msgs::CommonCommonStateBatteryStateChanged& level) {
	ROS_INFO("Battery level:  x=%d", level.percent);
	m_batteryLevel = level.percent;
	m_IsUpdated = true;

	std::string text = "BAT ---";
	text += std::to_string(m_batteryLevel);
	text += "%";

	m_origin = GetTextPosition();
}

void BatteryLevel::Draw(const cv_bridge::CvImagePtr& cv_ptr) {
	// Draw an example circle on the video stream
	if (m_IsUpdated) {
		m_color = m_batteryLevel < 10 ? defaults::ERROR_COLOR : defaults::COLOR;
		cv::putText(cv_ptr->image,
				m_text,
				m_origin,
				defaults::FONT_FACE,
				defaults::FONT_SCALE,
				m_color,
				defaults::THICKNESS, 8);
	}
}
}

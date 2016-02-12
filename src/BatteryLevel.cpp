/*
 * BatteryLevel.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include "ros/ros.h"

#include "BatteryLevel.h"
#include "UISettings.h"

namespace uav_hud {

static cv::Point GetTextPosition(){
	return cv::Point(defaults::MARGIN, 2*defaults::MARGIN);
}

BatteryLevel::BatteryLevel() : BaseGraphicElement(),
		m_text("BAT: ---")
{

}

void BatteryLevel::Update(const bebop_msgs::CommonCommonStateBatteryStateChanged& level) {
	ROS_INFO("Battery level:  x=%d", level.percent);
	unsigned int batteryLevel = level.percent;
	m_IsUpdated = true;

	m_text = "BAT ";
	m_text += std::to_string(batteryLevel);
	m_text += "%";

	m_origin = GetTextPosition();

	m_color = batteryLevel < 10 ? defaults::ERROR_COLOR : defaults::COLOR;
}

void BatteryLevel::Draw(const cv_bridge::CvImagePtr& cv_ptr) {
	// Draw an example circle on the video stream
	if (m_IsUpdated) {
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

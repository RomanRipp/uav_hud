/*
 * Altitude.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: robot
 */

#include "ros/ros.h"

#include "Altitude.h"

namespace uav_hud {

cv::Point GetTextPosition(
		const cv::Size& imageSize,
		const cv::Size& textSize)
{
	if (imageSize.width <= 0)
		return cv::Point(0.0, 0.0);

	int x = imageSize.width;
	x -= textSize.width;
	x -= defaults::MARGIN;
	int y = 2 * defaults::MARGIN;
	return (cv::Point(x, y));
}

Altitude::Altitude() : BaseGraphicElement(),
		m_text("ALT: ---") {
}

void Altitude::Update(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged& altitude)
{
	// ROS_INFO("Altitude changed z=%f", altitude.altitude);
	m_IsUpdated = true;

	m_text = "ALT ";
	m_text += std::to_string(altitude.altitude);
	m_text += "M";
}

void Altitude::Draw(const cv_bridge::CvImagePtr& cv_ptr)
{
	if (m_IsUpdated) {
		m_origin = GetTextPosition(
				GetSize(cv_ptr->image),
				GetSize(m_text));

		cv::putText(cv_ptr->image,
				m_text,
				m_origin,
				defaults::FONT_FACE,
				defaults::FONT_SCALE,
				m_color,
				defaults::THICKNESS, 8);
	}
}


} /* namespace uav_hud */

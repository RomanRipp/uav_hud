/*
 * FlyingState.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: robot
 */

#include "ros/ros.h"
#include "bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h"

#include "FlyingState.h"

namespace uav_hud {

static cv::Point GetTextPosition(const cv::Size& imageSize){
	if (imageSize.width <= 0)
		return cv::Point(0.0, 0.0);

	int x = imageSize.width / 2;
	int y = imageSize.height - defaults::MARGIN;
	return (cv::Point(x, y));
}

FlyingState::FlyingState() : BaseGraphicElement(),
		m_text("FlyingState ------") {
}

void FlyingState::Update(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged& state) {
	ROS_INFO("Flight state changed: %d", state.state);
	m_IsUpdated = true;
	m_color = defaults::COLOR;
	m_text = "FlyingState ";

	switch(state.state) {
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_emergency:
		m_text += "EMERGENCY";
		m_color = defaults::ERROR_COLOR;
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_flying:
		m_text += "FLYING";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_hovering:
		m_text += "HOVERING";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_landed:
		m_text += "LANDED";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_landing:
		m_text += "LANDING";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_takingoff:
		m_text += "TAKINGOFF";
		break;

	}
}

void FlyingState::Draw(const cv_bridge::CvImagePtr& cv_ptr) {
	//if (m_IsUpdated) {
	m_origin = GetTextPosition(GetSize(cv_ptr->image));
	cv::putText(cv_ptr->image,
			m_text,
			m_origin,
			defaults::FONT_FACE,
			defaults::FONT_SCALE,
			m_color,
			defaults::THICKNESS, 8);
	//}
}
}


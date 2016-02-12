/*
 * FlyingState.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: robot
 */

#include "FlyingState.h"
#include "bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h"

namespace uav_hud {

FlyingState::FlyingState() : BaseGraphicElement(),
		m_state(bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_landed),
		m_text("FlyingState: LANDED") {
}

void FlyingState::Update(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged& state) {
	m_state = state.state;
	m_IsUpdated = true;
	switch(m_state) {
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_emergency:
		m_text = "FlyingState: EMERGENCY";
		m_color = defaults::ERROR_COLOR;
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_flying:
		m_text = "FlyingState: FLYING";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_hovering:
		m_text = "FlyingState: HOVERING";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_landed:
		m_text = "FlyingState: LANDED";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_landing:
		m_text = "FlyingState: LANDING";
		break;
	case bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::state_takingoff:
		m_text = "FlyingState: TAKINGOFF";
		break;

	}
}

void FlyingState::Draw(const cv_bridge::CvImagePtr& cv_ptr) {

}
}


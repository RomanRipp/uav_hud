/*
 * RollPitchYaw.cpp
 *
 *  Created on: May 4, 2016
 *      Author: robot
 */

#include "RollPitchYaw.h"

namespace uav_hud {

RollPitchYaw::RollPitchYaw() : BaseGraphicElement(),
		m_orientation() {

}

void RollPitchYaw::Update(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged& state) {
	m_IsUpdated = true;

	m_orientation.setRPY(state.roll, state.pitch, state.yaw);
}

void RollPitchYaw::Draw(const cv_bridge::CvImagePtr& cv_ptr) {

}


} /* namespace uav_hud */

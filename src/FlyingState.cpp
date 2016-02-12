/*
 * FlyingState.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: robot
 */

#include "FlyingState.h"
#include "bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h"

namespace uav_hud {

FlyingState::FlyingState() {
// TODO Auto-generated constructor stub
}

void FlyingState::Update(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged& state) {
	m_state = state;
}

void FlyingState::Draw(const cv_bridge::CvImagePtr& cv_ptr) {

}
}


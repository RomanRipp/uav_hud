/*
 * FlyingState.h
 *
 *  Created on: Jan 20, 2016
 *      Author: robot
 */
#pragma once

#include "IGraphicElement.h"
#include "bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h"

namespace uav_hud {
class FlyingState : public IGraphicElement{
public:
	FlyingState();

	virtual void Update(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged& state);
	virtual void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
private:
	bebop_msgs::Ardrone3PilotingStateFlyingStateChanged m_state;
};
}

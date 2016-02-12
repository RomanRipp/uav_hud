/*
 * FlyingState.h
 *
 *  Created on: Jan 20, 2016
 *      Author: robot
 */
#pragma once

#include "IGraphicElement.h"
#include "BaseGraphicElement.h"

#include "bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h"

namespace uav_hud {
class FlyingState :
		public virtual IGraphicElement,
		public BaseGraphicElement {
public:
	FlyingState();

	virtual void Update(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged& state);
	virtual void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
private:
	unsigned int m_state;
	std::string m_text;
};
}

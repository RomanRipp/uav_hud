/*
 * FlyingState.h
 *
 *  Created on: Jan 20, 2016
 *      Author: robot
 */
#pragma once

#include "bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h"

#include "IGraphicElement.h"
#include "BaseGraphicElement.h"

namespace uav_hud {
class FlyingState :
		public virtual IGraphicElement,
		public BaseGraphicElement {
public:
	FlyingState();

	void Update(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged& state);
	void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
private:
	std::string m_text;
};
}

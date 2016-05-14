/*
 * RollPitchYaw.h
 *
 *  Created on: May 4, 2016
 *      Author: robot
 */

#pragma once

#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>

#include "BaseGraphicElement.h"
#include "IGraphicElement.h"

namespace uav_hud {

class RollPitchYaw :
		public BaseGraphicElement,
		public virtual IGraphicElement {
public:
	RollPitchYaw();

	void Update(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged& state);
	void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;

private:
	double m_roll;
	double m_pitch;
};

} /* namespace uav_hud */

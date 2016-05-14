/*
 * Altitude.h
 *
 *  Created on: Feb 12, 2016
 *      Author: robot
 */
#pragma once

#include "bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h"

#include "IGraphicElement.h"
#include "BaseGraphicElement.h"

namespace uav_hud {

class Altitude:
		public virtual IGraphicElement,
		public BaseGraphicElement {
public:
	Altitude();

public:
	void Update(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged& altitude);
	void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
private:
	std::string m_text;

};

} /* namespace uav_hud */

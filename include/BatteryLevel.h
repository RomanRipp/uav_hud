/*
 * BatteryLevel.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */
#pragma once

#include "bebop_msgs/CommonCommonStateBatteryStateChanged.h"

#include "IGraphicElement.h"
#include "BaseGraphicElement.h"

namespace uav_hud {

class BatteryLevel :
		public virtual IGraphicElement,
		public BaseGraphicElement
{
public:
	BatteryLevel();

public:
	void Update(const bebop_msgs::CommonCommonStateBatteryStateChanged& level);
	void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
private:
	std::string m_text;
};

}

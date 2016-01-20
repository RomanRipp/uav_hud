/*
 * BatteryLevel.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */
#pragma once

#include "IGraphicElement.h"
#include "bebop_msgs/CommonCommonStateBatteryStateChanged.h"

namespace uav_hud {

class BatteryLevel : public IGraphicElement {
public:
	BatteryLevel();

public:
	virtual void Update(const bebop_msgs::CommonCommonStateBatteryStateChanged& level);
	virtual void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
private:
	size_t m_batteryLevel;
};

}

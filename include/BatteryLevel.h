/*
 * BatteryLevel.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */
#pragma once

#include "IGraphicElement.h"
#include "std_msgs/Int32.h"

namespace uav_hud {

class BatteryLevel : public IGraphicElement {
public:
	BatteryLevel();
	virtual ~BatteryLevel();

public:
	virtual void Update(const std_msgs::Int32& level);
	virtual void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
	virtual void Erase() override;
};

}

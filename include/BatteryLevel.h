/*
 * BatteryLevel.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */
#pragma once

#include "IGraphicElement.h"

namespace uav_hud {

class BatteryLevel : public IGraphicElement {
public:
	BatteryLevel();
	virtual ~BatteryLevel();

public:
	virtual void Draw() override;
	virtual void Erase() override;
};

}

/*
 * IGraphicElement.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#pragma once

#include <cv_bridge/cv_bridge.h>

namespace uav_hud {

class IGraphicElement
{
public:
	virtual void Draw(const cv_bridge::CvImagePtr& cv_ptr) = 0;
	virtual void Erase() = 0;

public:
	virtual ~IGraphicElement(){};
};

}

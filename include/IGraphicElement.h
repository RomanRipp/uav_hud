/*
 * IGraphicElement.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#pragma once

namespace uav_hud {

class IGraphicElement
{
public:
	virtual void Draw() = 0;
	virtual void Erase() = 0;

public:
	virtual ~IGraphicElement();
};

}

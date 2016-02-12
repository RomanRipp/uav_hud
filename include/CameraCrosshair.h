/*
 * CameraCrosshair.h
 *
 *  Created on: Feb 12, 2016
 *      Author: robot
 */
#pragma once

#include "bebop_msgs/Ardrone3CameraStateOrientation.h"

#include "IGraphicElement.h"
#include "BaseGraphicElement.h"

namespace uav_hud {

class CameraCrosshair :
		public virtual IGraphicElement,
		public BaseGraphicElement {
public:
	CameraCrosshair();

public:
	virtual void Update(const bebop_msgs::Ardrone3CameraStateOrientation& level);
	virtual void Draw(const cv_bridge::CvImagePtr& cv_ptr) override;
};

} /* namespace uav_hud */

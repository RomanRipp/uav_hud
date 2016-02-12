/*
 * BaseGraphicElement.h
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#pragma once

#include "UISettings.h"

namespace uav_hud {

class BaseGraphicElement {
public:
	BaseGraphicElement();
	virtual ~BaseGraphicElement();

protected:
	cv::Size GetSize(const cv::Mat& image) const;
	cv::Size GetSize(const std::string& text) const;

protected:
	bool m_IsUpdated;
	cv::Point m_origin;
	cv::Scalar m_color;
};

} /* namespace uav_hud */

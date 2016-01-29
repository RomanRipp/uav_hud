/*
 * BaseGraphicElement.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include "opencv2/opencv.hpp"
#include "BaseGraphicElement.h"

namespace uav_hud {

BaseGraphicElement::BaseGraphicElement() : m_IsUpdated(false)
{
	// TODO Auto-generated constructor stub

}

BaseGraphicElement::~BaseGraphicElement() {
	// TODO Auto-generated destructor stub
}

cv::Size BaseGraphicElement::GetSize(const cv::Mat& image) const {
	return image.size();
}

cv::Size BaseGraphicElement::GetSize(const std::string& text) const {
	int baseLine(0);
	return cv::getTextSize(text, defaults::FONT_FACE, defaults::FONT_SCALE,
			defaults::THICKNESS, &baseLine);
}
} /* namespace uav_hud */

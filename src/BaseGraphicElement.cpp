/*
 * BaseGraphicElement.cpp
 *
 *  Created on: Jan 13, 2016
 *      Author: robot
 */

#include "BaseGraphicElement.h"
#include "opencv2/opencv.hpp"

namespace uav_hud {

BaseGraphicElement::BaseGraphicElement() : m_IsUpdated(false),
		m_color(defaults::COLOR), m_origin(cv::Point(0.0, 0.0)) {

}

BaseGraphicElement::~BaseGraphicElement() {
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

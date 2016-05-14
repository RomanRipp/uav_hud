/*
 * CameraCrosshair.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: robot
 */

#include "CameraCrosshair.h"

namespace uav_hud {

static void DrawCameraCenter(const cv_bridge::CvImagePtr& cv_ptr) {
	const auto& imageSize(cv_ptr->image.size());
	if (imageSize.height <= 0 || imageSize.width <= 0)
		return;

	cv::Point center(imageSize.width / 2, imageSize.height / 2);
	cv::circle(cv_ptr->image,
			center,
			defaults::MARGIN,
			defaults::COLOR2,
			defaults::THICKNESS,
			8, 0);

	cv::line(cv_ptr->image,
			cv::Point(center.x - defaults::MARGIN, center.y),
			cv::Point(center.x - 1.5 * defaults::MARGIN, center.y),
			defaults::COLOR2,
			defaults::THICKNESS,
			8, 0);

	cv::line(cv_ptr->image,
			cv::Point(center.x + defaults::MARGIN, center.y),
			cv::Point(center.x + 1.5 * defaults::MARGIN, center.y),
			defaults::COLOR2,
			defaults::THICKNESS,
			8, 0);

	cv::line(cv_ptr->image,
			cv::Point(center.x, center.y + defaults::MARGIN),
			cv::Point(center.x, center.y  + 1.5 * defaults::MARGIN),
			defaults::COLOR2,
			defaults::THICKNESS,
			8, 0);
}

CameraCrosshair::CameraCrosshair() :
	BaseGraphicElement() {
}

void CameraCrosshair::Update(const bebop_msgs::Ardrone3CameraStateOrientation& orientation)
{

}

void CameraCrosshair::Draw(const cv_bridge::CvImagePtr& cv_ptr)
{
	DrawCameraCenter(cv_ptr);
}

} /* namespace uav_hud */

/*
 * RollPitchYaw.cpp
 *
 *  Created on: May 4, 2016
 *      Author: robot
 */

#include "RollPitchYaw.h"

#include <ros/ros.h>
#include <tf/tf.h>
#include <cmath>

namespace uav_hud {

RollPitchYaw::RollPitchYaw() : BaseGraphicElement(),
		m_roll(0.0), m_pitch(0.0){

}

void RollPitchYaw::Update(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged& state) {
	m_IsUpdated = true;

	m_roll = state.roll;
	m_pitch =  state.pitch;
}

void RollPitchYaw::Draw(const cv_bridge::CvImagePtr& cv_ptr) {

	const auto& imageSize(cv_ptr->image.size());
	if (imageSize.height <= 0 || imageSize.width <= 0)
		return;

	double l = std::min(imageSize.height / 2, imageSize.width / 2);
//	tf::Transform transform;
//	transform.setOrigin(tf::Vector3(0.0, l, 0.0));
//	tf::Quaternion orientation;
//	orientation.setRPY(m_roll, m_pitch, 0.0);
//	transform.setRotation(orientation);
//
//	tf::Transform point1;
//	point1.setOrigin(tf::Vector3(imageSize.width / 4, imageSize.height / 2, 0.0));
//	tf::Transform point2;
//	point2.setOrigin(tf::Vector3(imageSize.width / 2 - 2 * defaults::MARGIN, imageSize.height / 2, 0.0));
//
//	point1 = point1 * transform;
//	point2 = point2 * transform;

	double dy = std::sin(m_pitch) * l;

	auto x1 = imageSize.width / 4;
	auto x2 = imageSize.width / 2;
	auto y1 = imageSize.height / 2 + dy;

	cv::Point pt1(x1, y1);
	cv::Point pt2(x2 - 2 * defaults::MARGIN, y1);
	cv::line(cv_ptr->image,
			pt1,
			pt2,
			defaults::COLOR,
			defaults::THICKNESS,
			8, 0);

	pt1 = cv::Point(3 * x1, y1);
	pt2 = cv::Point(x2 + 2 * defaults::MARGIN, y1);
	cv::line(cv_ptr->image,
			pt1,
			pt2,
			defaults::COLOR,
			defaults::THICKNESS,
			8, 0);

	if (m_IsUpdated) {
		std::string text = std::to_string(m_pitch * 3.14);
		cv::putText(cv_ptr->image,
				text,
				pt2,
				defaults::FONT_FACE,
				defaults::FONT_SCALE,
				m_color,
				defaults::THICKNESS, 8);
	}
}


} /* namespace uav_hud */

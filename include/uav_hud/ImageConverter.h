/*
 * ImageConverter.h
 *
 *  Created on: Jan 8, 2016
 *      Author: robot
 */
#pragma once

#include <ros/ros.h>
#include <image_transport/image_transport.h>

namespace uav_hud {
class ImageConverter
{
public:
	ImageConverter();
	~ImageConverter();

	void Convert(const sensor_msgs::ImageConstPtr& message);

private:
	ros::NodeHandle m_nodeHandle;
	image_transport::ImageTransport m_imageTransport;
	image_transport::Subscriber     m_imageSubscriber;
	image_transport::Publisher      m_imagePublisher;
};
}

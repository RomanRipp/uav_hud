/*
 * ImageConverter.h
 *
 *  Created on: Jan 8, 2016
 *      Author: robot
 */
#pragma once

#include <memory>
#include <vector>

#include <ros/ros.h>
#include <image_transport/image_transport.h>

#include "IGraphicElement.h"

namespace uav_hud {

typedef std::unique_ptr<IGraphicElement> IGraphicElementPtr;

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
	ros::Subscriber                 m_batteryLevelSubscriber;

	std::vector<IGraphicElementPtr> m_graphicElements;
};
}

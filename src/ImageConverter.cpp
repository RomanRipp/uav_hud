/*
 * ImageConverter.cpp
 *
 *  Created on: Jan 8, 2016
 *      Author: robot
 */

#include <vector>
#include <memory>

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ros_topics.h"
#include "ImageConverter.h"
#include "BatteryLevel.h"

namespace uav_hud {

static const std::string OPENCV_WINDOW = "Image window";

ImageConverter::ImageConverter()
	: m_imageTransport(m_nodeHandle)
{
	// Initialize subscribers
	m_imageSubscriber = m_imageTransport.subscribe(Topics::INPUT_VIDEO(),
			1, &ImageConverter::Convert, this);

	// Initialize publishers
    m_imagePublisher = m_imageTransport.advertise(Topics::OUTPUT_VIDEO(), 1);

    // Initialize graphic elements
    m_graphicElements.push_back(IGraphicElementPtr(new BatteryLevel()));


    cv::namedWindow(OPENCV_WINDOW);
}

ImageConverter::~ImageConverter()
{
	cv::destroyWindow(OPENCV_WINDOW);
}

void ImageConverter::Convert(const sensor_msgs::ImageConstPtr& message)
{
	// Convert to open cv format
	cv_bridge::CvImagePtr cv_ptr;
	try {
		cv_ptr = cv_bridge::toCvCopy(message, sensor_msgs::image_encodings::BGR8);
	} catch (cv_bridge::Exception& e) {
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	}

	// Draw hud
	for (const auto& graphicElement : m_graphicElements)
	{
		graphicElement->Draw(cv_ptr);
	}

	// Update GUI Window
	cv::imshow(OPENCV_WINDOW, cv_ptr->image);
	cv::waitKey(3);

	// Output modified video stream
	m_imagePublisher.publish(cv_ptr->toImageMsg());
}
}



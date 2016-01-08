/*
 * ImageConverter.cpp
 *
 *  Created on: Jan 8, 2016
 *      Author: robot
 */

#include "uav_hud/ImageConverter.h"
#include "uav_hud/ros_topics.h"

#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace uav_hud{

static const std::string OPENCV_WINDOW = "Image window";

ImageConverter::ImageConverter()
	: m_imageTransport(m_nodeHandle)
{
	m_imageSubscriber = m_imageTransport.subscribe(Topics::INPUT_VIDEO(),
			1, &ImageConverter::Convert, this);

    m_imagePublisher = m_imageTransport.advertise(Topics::OUTPUT_VIDEO(), 1);

    cv::namedWindow(OPENCV_WINDOW);
}

ImageConverter::~ImageConverter()
{
	cv::destroyWindow(OPENCV_WINDOW);
}

void ImageConverter::Convert(const sensor_msgs::ImageConstPtr& message)
{
	cv_bridge::CvImagePtr cv_ptr;
	try {
		cv_ptr = cv_bridge::toCvCopy(message, sensor_msgs::image_encodings::BGR8);
	} catch (cv_bridge::Exception& e) {
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	}

	// Draw an example circle on the video stream
	if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
		cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255, 0, 0));

	// Update GUI Window
	cv::imshow(OPENCV_WINDOW, cv_ptr->image);
	cv::waitKey(3);

	// Output modified video stream
	m_imagePublisher.publish(cv_ptr->toImageMsg());
}
}



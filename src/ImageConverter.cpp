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

#include <QImage>
#include <QObject>
#include <QQuickImageProvider>

#include "ros_topics.h"
#include "ImageConverter.h"
#include "BatteryLevel.h"
#include "FlyingState.h"

namespace uav_hud {

static QImage Mat2QImage(cv::Mat const& src)
{
     cv::Mat temp(src.cols,src.rows,src.type());
     cvtColor(src, temp,CV_BGR2RGB);
     QImage dest= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     return dest;
}


class ColorPixmapProvider : public QQuickImageProvider
{
public:
	ColorPixmapProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
    {
        int width = 100;
        int height = 50;

        if (size)
            *size = QSize(width, height);
        QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                       requestedSize.height() > 0 ? requestedSize.height() : height);
        pixmap.fill(QColor(id).rgba());

        return pixmap;
    }
};


ImageConverter::ImageConverter()
	: m_imageTransport(m_nodeHandle),
	  m_qtEngine()
{
	// Initialize QT
	m_qtEngine.load(QUrl(QStringLiteral("qrc:/qml/hud.qml")));
	m_qtEngine.addImageProvider(QLatin1String("colors"), new ColorPixmapProvider);

	// Initialize graphic elements
	std::unique_ptr<BatteryLevel> batteryLevelPtr(new BatteryLevel());
	std::unique_ptr<FlyingState>  flyingStatePtr(new FlyingState());

	// Initialize subscribers
	m_imageSubscriber = m_imageTransport.subscribe(Topics::INPUT_VIDEO,
			1, &ImageConverter::Convert, this);
	m_batteryLevelSubscriber = m_nodeHandle.subscribe(Topics::BATTERY_LEVEL,
			1, &BatteryLevel::Update, batteryLevelPtr.get());
	m_batteryLevelSubscriber = m_nodeHandle.subscribe(Topics::FLYING_STATE,
			1, &FlyingState::Update, flyingStatePtr.get());

	// Initialize publishers
    m_imagePublisher = m_imageTransport.advertise(Topics::OUTPUT_VIDEO, 1);

    //Collect graphics elements;
    m_graphicElements.push_back(std::move(batteryLevelPtr));
    m_graphicElements.push_back(std::move(flyingStatePtr));

    //cv::namedWindow(OPENCV_WINDOW);
}

ImageConverter::~ImageConverter()
{
	//cv::destroyWindow(OPENCV_WINDOW);
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

	const auto& image(Mat2QImage(cv_ptr->image));

//	QObject* imageObject = m_qtEngine.findChild<QObject*>("Image");
//	QImage* currentImage = qobject_cast<QImage*>(imageObject);


	// Draw hud
	for (const auto& graphicElement : m_graphicElements)
	{
		//graphicElement->Draw(cv_ptr);
	}

	// Update GUI Window
    // cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    // cv::waitKey(3);



	// Output modified video stream
	m_imagePublisher.publish(cv_ptr->toImageMsg());
}
}



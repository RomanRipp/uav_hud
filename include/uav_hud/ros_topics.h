/*
 * ros_topics.h
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#pragma once

#include <string>

namespace uav_hud{

class Topics
{
	//Input topics:
	const static std::string INPUT_VIDEO = "uav_hud/input_image";

	//Output topics
	const static std::string OUTPUT_VIDEO = "uav_hud/output_image";
};

}



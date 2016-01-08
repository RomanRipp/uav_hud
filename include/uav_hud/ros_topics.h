/*
 * ros_topics.h
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#pragma once

#include <string>

namespace uav_hud {
class Topics {
  // Input topics:
public:
  static const std::string INPUT_VIDEO()
  {
	  return "/bebop/image_raw";
  }

  // Output topics
  static const std::string OUTPUT_VIDEO()
  {
	  return INPUT_VIDEO() + "/uav_hud";
  }
};
}

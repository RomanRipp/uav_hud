/*
 * ros_topics.h
 *
 *  Created on: Dec 29, 2015
 *      Author: Roman
 */

#pragma once

#include <string>

namespace uav_hud {
namespace Topics {
  // Input topics:
  static const std::string INPUT_VIDEO = "image_raw";
  static const std::string BATTERY_LEVEL = "battery_level";
  static const std::string FLYING_STATE = "flying_state";
  static const std::string ALTITUDE = "altitude";
  static const std::string ATTITUDE = "attitude";
  static const std::string CAMERA_ORIENTATION = "camera_orientation";

  // Output topics
  static const std::string OUTPUT_VIDEO = INPUT_VIDEO + "/uav_hud";
};
}

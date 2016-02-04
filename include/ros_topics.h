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
  static const std::string INPUT_VIDEO   = "image_raw";
  static const std::string BATTERY_LEVEL = "battery_level";
  static const std::string FLYING_STATE  = "states/ARDrone3/PilotingState/FlyingStateChanged";

  // Output topics
  static const std::string OUTPUT_VIDEO = INPUT_VIDEO + "/uav_hud";
};
}

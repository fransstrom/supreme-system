#pragma once
#include "AirSensor.hpp"
#include <vector>
class AirMonitor {
  std::vector<AirSensor> airSensors;

public:
  AirMonitor(std::vector<AirSensor> &airSensors) : airSensors(airSensors) {};
  void logAll() const;
};

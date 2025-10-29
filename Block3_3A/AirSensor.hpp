#pragma once
#include "../SensorReading.hpp"
#include <string>

class AirSensor {
public:
  AirSensor(const std::string& name);
  std::string getName() const;
  SensorReading read() const;

private:
  std::string name;
};

#pragma once
#include <string>

struct SensorReading {
  double value;
  std::string timestamp;
  std::string sensorName;

  void print() const;
};

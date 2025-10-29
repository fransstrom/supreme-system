#include "AirSensor.hpp"
#include "SensorReading.hpp"
SensorReading AirSensor::read() {
  SensorReading sensorReading = {.value = 12.2, .timestamp = "2025-10-12"};
  return sensorReading;
}

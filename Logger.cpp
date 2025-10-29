#include "Logger.hpp"
#include "SensorReading.hpp"
#include <iostream>
#include <string>

// void Logger::move(double dx, double dy)
void Logger::log(const SensorReading &reading,
                 const std::string &sensorName) const {
  std::cout << "\n" << sensorName << " logger \ntimestamp: "<< reading.timestamp<<"\nvalue: "<< reading.value<<"\n";
}

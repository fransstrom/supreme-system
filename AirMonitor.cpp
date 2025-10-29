#include "AirMonitor.hpp"
#include "Logger.hpp"
#include <iostream>
void AirMonitor::logAll() const {
  Logger logger;
  std::cout << "Logging all airsensors\n";
  for (auto airSensor : airSensors) {
    logger.log(airSensor.read(), airSensor.getName());
  }
}

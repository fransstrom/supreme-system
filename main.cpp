#include "AirMonitor.hpp"
#include "AirSensor.hpp"
#include "Device.hpp"
#include "Logger.hpp"
#include "Position.hpp"
#include "Sensor.hpp"
#include "SensorReading.hpp"
#include <vector>
int main(int argc, char *argv[]) {
  // Position
  Position pos;
  pos.print();
  pos.move(8.3232, 13.3232);
  pos.print();
  // Device
  Device dev(1, "Arduino");
  dev.printInfo();
  dev.rename("ESP32");
  dev.printInfo();
  // Sensor
  Sensor sensor("Humidity sensor");
  auto sensorReading = sensor.read();
  sensorReading.print();
  // Logger
  Logger logger;
  logger.log(sensorReading, sensor.getName());
  // AirSensor
  AirSensor airSensor1;
  AirSensor airSensor2;
  AirSensor airSensor3;

  std::vector<AirSensor> airSensorVector = {
      airSensor1,
      airSensor2,
      airSensor3,
  };
  AirMonitor airMonitor(airSensorVector);
  airMonitor.logAll();

  return 0;
}

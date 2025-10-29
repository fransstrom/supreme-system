#include "Device.hpp"
#include "Logger.hpp"
#include "Position.hpp"
#include "Sensor.hpp"

#include "AirSensor.hpp"
#include "AirMonitor.hpp"

int main(int argc, char *argv[]) {

  Position pos;
  pos.print();
  pos.move(8.3232, 13.3232);
  pos.print();

  Device dev(1, "Arduino");
  dev.printInfo();
  dev.rename("ESP32");
  dev.printInfo();

  Sensor sensor("Humidity sensor");
  auto sensorReading = sensor.read();
  sensorReading.print();

  Logger logger;
  logger.log(sensorReading,sensor.getName());

  //  NEW 'AirMonitor', 'AirSensor'
  AirSensor s1("Temp sensor");
  AirSensor s2("CO2 sensor");
  AirSensor s3("Humidity sensor");

  AirMonitor monitor;
    monitor.addSensor(s1);
    monitor.addSensor(s2);
    monitor.addSensor(s3);

    monitor.logAll();

  return 0;
}

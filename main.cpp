#include "AirMonitor.hpp"
#include "AirSensor.hpp"
#include "Car.hpp"
#include "Device.hpp"
#include "Logger.hpp"
#include "ParkingHouse.hpp"
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
  AirSensor airSensor1("Air sensor 1");
  AirSensor airSensor2("Air sensor 2");
  AirSensor airSensor3("Air sensor 3");

  std::vector<AirSensor> airSensorVector = {
      airSensor1,
      airSensor2,
      airSensor3,
  };
  AirMonitor airMonitor(airSensorVector);
  airMonitor.logAll();

  // Car
  Car car1 = {.regNumber = "WJS123", .arrivalTime = "2025-10-30"};
  Car car2 = {.regNumber = "WJS113", .arrivalTime = "2025-10-30"};
  Car car3 = {.regNumber = "WJS133", .arrivalTime = "2025-10-30"};
  car1.print();

  ParkingHouse ph;
  ph.addCar(car1);
  ph.addCar(car2);
  ph.addCar(car3);
  ph.printStatus();
  ph.removeCar(car3.regNumber);
  ph.printStatus();
  return 0;
}

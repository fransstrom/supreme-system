#include "AirMonitor.hpp"
#include "AirSensor.hpp"
#include "Car.hpp"
#include "Device.hpp"
#include "Logger.hpp"
#include "ParkingHouse.hpp"
#include "Position.hpp"
#include "Sensor.hpp"
#include "SensorReading.hpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
void tfun() {
  while (true) {

    std::cout << "HEJ THREAD 1\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
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
  Car car2 = {.regNumber = "OJS113", .arrivalTime = "2025-10-29"};
  Car car3 = {.regNumber = "LSS133", .arrivalTime = "2025-10-28"};
  car1.print();
  std::string car2red = "WJS123";
  std::string car3red = "WJS133";
  ParkingHouse ph;
  ph.addCar(car1);
  ph.addCar(car2);
  ph.addCar(car3);
  ph.printStatus();
  ph.printStatus();

  std::thread t1([&ph, &car2red]() {
    while (true) {
      ph.printStatus();
      std::this_thread::sleep_for(std::chrono::seconds(2));
      ph.removeCar(car2red);
    }
  });
  t1.detach();

  std::thread t2(tfun);
  t2.detach();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::this_thread::sleep_for(std::chrono::seconds(2));
  ph.removeCar(car3red);
  std::this_thread::sleep_for(std::chrono::seconds(2));
  ph.printStatus();
  std::this_thread::sleep_for(std::chrono::seconds(1000));
  return 0;
}

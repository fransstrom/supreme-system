#pragma once
#include "Car.hpp"
#include <vector>
class ParkingHouse {
public:
  void addCar(Car &car);
  void printStatus();
  void removeCar(std::string &regNumber);

private:
  std::vector<Car> cars;
};

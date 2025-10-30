#include "ParkingHouse.hpp"
#include "Car.hpp"
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
#include <string>
#include <vector>

void ParkingHouse::addCar(Car &car) { cars.push_back(car); }
void ParkingHouse::printStatus() {
  std::cout << "\nParking house status\n";
  for (auto &car : cars) {
    std::cout << car.regNumber << " : Arrival " << car.arrivalTime << "\n";
  }
}

void ParkingHouse::removeCar(std::string &regNumber) {
  std::vector<Car>::iterator it = cars.begin();
  while (it != cars.end()) {
    if (it->regNumber == regNumber) {
      cars.erase(it);
    } else {
      ++it;
    }
  }
}

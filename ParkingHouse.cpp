#include "ParkingHouse.hpp"
#include "Car.hpp"
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
#include <string>
#include <vector>

void ParkingHouse::addCar(Car &car) { cars.push_back(car); }
void ParkingHouse::printStatus() {

  std::vector<Car>::iterator it = cars.begin();
  std::cout << "\nGarage cars parkedGarage cars parked:\n";
  while (it != cars.end()) {
    it->print();
    it++;
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

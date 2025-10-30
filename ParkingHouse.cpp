#include "ParkingHouse.hpp"
#include "Car.hpp"
#include <iostream>
#include <string>

void ParkingHouse::addCar(Car &car) { cars.push_back(car); }
void ParkingHouse::printStatus() {
  std::cout << "\nParking house status\n";
  for (auto &car : cars) {
    std::cout << car.regNumber << " : Arrival " << car.arrivalTime << "\n";
  }
}

void ParkingHouse::removeCar(std::string &regNumber) {
  for (unsigned int i = 0; i < cars.size(); i++) {
    if (regNumber == cars.at(i).regNumber) {
      cars.erase(cars.begin() + i);
    }
  }
}

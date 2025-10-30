#include "ParkingHouse.hpp"
#include <iostream>
#include <algorithm> // for std::remove_if

void ParkingHouse::addCar(const Car& car) {
    cars.push_back(car);  // add 'car' to vector
}

bool ParkingHouse::removeCar(const std::string& regNumber) {
    auto it = std::remove_if(cars.begin(), cars.end(), [&](const Car& c) {
        return c.regNumber == regNumber;
    });
    
    if (it != cars.end()) {
        cars.erase(it, cars.end());
        return true;
    }
    return false;
}

void ParkingHouse::printStatus() const {
    std::cout << "Parked cars:\n";
    std::cout << std::endl;
    for (const auto& car : cars) {
        std::cout << "-\t";
        car.print();
    }
}

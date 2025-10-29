#include "Car.hpp"
#include "ParkingHouse.hpp"
#include <vector>
#include <string>

void Car::print() const {
    std::cout << "\tCar '" << regNumber << "' arrived at " << arrivalTime << "\n";
}
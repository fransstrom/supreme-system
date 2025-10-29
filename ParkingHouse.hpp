#pragma once
#include "Car.hpp"
#include <string>
#include <vector>

class ParkingHouse
{
    private:
        std::vector<Car> cars;  // Store cars

    public:
        void addCar(const Car& car);
        bool removeCar(const std::string& regNumber);

        void printStatus() const;
};
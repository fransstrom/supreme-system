#include "SensorReading.hpp"
#include <iostream>

void SensorReading::print() const {
    std::cout << "\nSensor reading:\n"<< timestamp<< ": "   << value << "\n";
};

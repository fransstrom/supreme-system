#include "SensorReading.hpp"
#include <iostream>

void SensorReading::print() const {
    std::cout << "\n" << value << " and " << timestamp << "\n";
};
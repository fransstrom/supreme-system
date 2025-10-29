#include "SensorReading.hpp"
#include <iostream>

void SensorReading::print() const {
    std::cout << "\n"<< sensorName << " reading:\n"<< timestamp<< ": "   << value << "\n";
};

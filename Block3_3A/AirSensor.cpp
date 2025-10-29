#include <cstdlib>
#include <ctime>

#include "AirSensor.hpp"
#include "../SensorReading.hpp"

AirSensor::AirSensor(const std::string& name)
    : name(name) 
{
    // std::srand(std::time(nullptr)); 
    std::srand(static_cast<unsigned>(std::time(nullptr))); 
}

std::string AirSensor::getName() const {
    return name;
}

SensorReading AirSensor::read() const 
{
    SensorReading reading;
    reading.value = static_cast<double>(std::rand() % 100); // A Random test value
    reading.timestamp = "N/A";  // A timestamp placeholder

    return reading;
}
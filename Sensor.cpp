#include <string>
#include "Sensor.hpp"

Sensor::Sensor(const std::string &name): name(name)
    {}

SensorReading Sensor::read() const {
     SensorReading sr;
     sr.sensorName=name;
     sr.value=15.32;
     sr.timestamp ="2025-10-28";

     return sr;
};

std::string Sensor::getName() const {
    return name;
};

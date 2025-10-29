#pragma once
#include "SensorReading.hpp"
#include <string>
class Sensor 
{
    private:
        std::string name;

    public:
        Sensor(const std::string& name);
        SensorReading read() const;
        std::string getName() const;
};
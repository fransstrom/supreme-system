#pragma once
#include "SensorReading.hpp"
#include <string>

class Logger 
{
    public:
        void log(const SensorReading& reading, const std::string& 
            sensorName) const;
};
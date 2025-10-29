#include "Logger.hpp"
#include "AirMonitor.hpp"

AirMonitor::AirMonitor(const std::vector<AirSensor>& sensors) 
    : sensors(sensors) 
    {}

void AirMonitor::addSensor(const AirSensor& sensor)
{
    sensors.push_back(sensor);
}

void AirMonitor::logAll() const
{
    Logger logger;
    for (const auto& sensor 
        : sensors)
    {
        SensorReading reading = sensor.read();
        logger.log(reading, sensor.getName());
    }
}
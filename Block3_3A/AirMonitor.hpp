#pragma once
#include "AirSensor.hpp"
#include <vector>

class AirMonitor
{
public:
	AirMonitor() = default;
	AirMonitor(const std::vector<AirSensor>& sensors);

	void addSensor(const AirSensor& sensor);
	void logAll() const;

private:
	std::vector<AirSensor> sensors;
};
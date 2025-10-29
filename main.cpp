#include <iostream>
#include "Device.hpp"
#include "Logger.hpp"
#include "Position.hpp"
#include "Sensor.hpp"

#include "Block3_3A/AirSensor.hpp"
#include "Block3_3A/AirMonitor.hpp"

#include "Car.hpp"
#include "ParkingHouse.hpp"

int main(int argc, char* argv[]) {

	Position pos;
	pos.print();
	pos.move(8.3232, 13.3232);
	pos.print();

	Device dev(1, "Arduino");
	dev.printInfo();
	dev.rename("ESP32");
	dev.printInfo();

	Sensor sensor("Humidity sensor");
	auto sensorReading = sensor.read();
	sensorReading.print();

	Logger logger;
	logger.log(sensorReading, sensor.getName());

	/* 3a - 'AirMonitor', 'AirSensor' (Gör till funktion?)
	*/
	AirSensor s1("Temp sensor");
	AirSensor s2("CO2 sensor");
	AirSensor s3("Humidity sensor");

	AirMonitor monitor;
	monitor.addSensor(s1);
	monitor.addSensor(s2);
	monitor.addSensor(s3);

	monitor.logAll();

	/* 3b - 'Car', 'ParkingHouse'
	*/
	std::cout << "\nParking House Garage" << std::endl;
	ParkingHouse parkedCar;

	Car car1{ "IOTK25", "12:34" };
	Car car2{ "FRA111", "23:01" };
	Car car3{ "LOV222", "04:34" };

	parkedCar.addCar(car1);
	parkedCar.addCar(car2);
	parkedCar.addCar(car3);

	//  PRINT STATUS
	parkedCar.printStatus();

	//  REMOVE CAR
	std::string regToRm;
	std::cout << "\nOne car needs to be removed, write registration number.\nChoose:\t";
	std::cin >> regToRm;

	bool removed = parkedCar.removeCar(regToRm);

	if (removed)
	{
		std::cout << "\nCar '" << regToRm << "' has left this parking house.\n";
	}
	else
	{
		std::cout << "\nNo car with registration '" << regToRm << "' was found.\n";
	}

	std::cout << "\n[Status Updated]\n";  //  POST REMOVAL STATUS
	parkedCar.printStatus();
	std::cout << std::endl;

	return 0;
}

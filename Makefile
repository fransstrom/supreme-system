all:
	g++ -Wall -g main.cpp Position.cpp Device.cpp Sensor.cpp SensorReading.cpp -o main -std=c++20
	./main

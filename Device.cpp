#include "Device.hpp"
#include <iostream>
#include <string>

Device::Device(int id, const std::string &name)
    : id(id), name(name) // member initializer list
{}

void Device::rename(const std::string &newName) { name = newName; }

void Device::printInfo() const {
  std::cout << "Device id: " << id << "\n" << "Device name: " << name << "\n";
}

#include "Device.hpp"
#include <iostream>
#include <string>

void Device::rename(const std::string &newName) { name = newName; }
void Device::printInfo() const {
  std::cout << "Device id: " << id << "\n" << "Device name: " << name << "\n";
}

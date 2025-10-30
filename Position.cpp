#include "Position.hpp"
#include <iostream>

void Position::move(double dx, double dy) {
  this->x += dx;
  this->y += dy;
  return;
};

void Position::print() const {
  std::cout << "\nPosition X:\t" << x << "\nPosition Y:\t" << y << "\n";
}

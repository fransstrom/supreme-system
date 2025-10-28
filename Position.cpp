#include "Position.hpp"
#include <iostream>

void Position::move(double dx, double dy) 
{
    x += dx;
    y += dy;

    return;
};

void Position::print() const 
{
    std::cout << "Position X:\t" << x << "\nPosition Y:\t" << y;
}
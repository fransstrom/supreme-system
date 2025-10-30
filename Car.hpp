#pragma once
#include <string>
#include <iostream>

struct Car {
    std::string regNumber;
    std::string arrivalTime;

    void print() const;  // const eftersom vi inte ändrar bilen när vi skriver ut
};

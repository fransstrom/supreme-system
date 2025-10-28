#include <iostream>
#include "Position.hpp"

int main (int argc, char *argv[]) 
{
  Position pos;
  pos.print();

  pos.move(8.3232, 13.3232);

  pos.print();
  return 0;
}

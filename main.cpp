#include "Device.hpp"
#include "Position.hpp"
int main(int argc, char *argv[]) {
  Position pos;
  pos.print();

  pos.move(8.3232, 13.3232);

  pos.print();
  Device dev(1, "Firesensor"); 
  dev.printInfo();
  dev.rename("watersensore");
  dev.printInfo();

  return 0;
}

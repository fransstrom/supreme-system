Övningsuppgifter – Dag 1 (28/10)
Arbetssätt: Parvis eller individuellt

## Syfte
    ● Du ska få trygghet i att definiera egna typer i C++: klasser och structs.
    ● Du ska kunna använda separata filer (.h och .cpp) för gränssnitt och

## implementation.
    ● Du ska kunna instansiera objekt, anropa metoder och se hur objekten samverkar.
    ● Vi försöker hålla oss utan arv denna första dag — fokus på grundläggande objektorientering och struktur.

# Block 1 – Grundläggande klasser & structs
### Övning 1A – Fyll i klass och struct

//  Del 1: Position (struct)
struct Position {
    double x;
    double y;
    
    void move(double dx, double dy); // Flytta punkten
    void print() const; // Skriv ut positionen
};

## Uppgifter:
    1. Skapa filen Position.h och deklarera ovan struct i den.
    2. Skapa filen Position.cpp och implementera move() och print().
        ○ move(dx,dy) ska addera dx och dy till x respektive y.
        ○ print() ska skriva ut något i stil med Position(x=…, y=…).
    3. I filen main.cpp, inkludera "Position.h", skapa ett Position‑objekt, flytta det
        (t.ex. move(3.0, -1.5)), och kalla print().
    4. Kör programmet och verifiera att utskriften stämmer.

//  Del 2: Device (klass)
class Device {
    private:
        int id;
        std::string name;
    public:
        Device(int id, const std::string& name);
        void rename(const std::string& newName);
        void printInfo() const;
};

## Uppgifter:
    1. Skapa Device.h och deklarera klassen där.
    2. Skapa Device.cpp och implementera:
        ○ Konstruktor som initialiserar id och name.
        ○ rename(newName) som uppdaterar name.
        ○ printInfo() som skriver ut t.ex. Device(id=…, name=…).
    3. I main.cpp, efter Position‑delen, skapa minst två Device‑objekt med olika id och namn.
    4. Anropa printInfo() för varje objekt, kall sedan rename() på ett objekt och skriv ut igen för att verifiera att namnändringen fungerar.

# Block 2 – Sensor, Reading och Logger
### Övning 2A – Implementera klasser
### Scenario:
    Ett IoT‑system ska samla in mätvärden från en sensor, paketera dem som en “reading”, och logga dem.

###### Filer och klasser/structs:

SensorReading (struct)
    struct SensorReading {
    double value;
    std::string timestamp;
    void print() const;
};

//  Sensor (klass)
class Sensor {
    private:
    std::string name;
    public:
    Sensor(const std::string& name);
    SensorReading read() const;
    std::string getName() const;
};
//  Logger (klass)
class Logger {
    public:
        void log(const SensorReading& reading, const std::string&
        sensorName) const;
};
//  Uppgifter:
    1. Skapa filer: SensorReading.h, SensorReading.cpp; Sensor.h, Sensor.cpp;
        Logger.h, Logger.cpp.
    2. Implementera SensorReading::print() som skriver ut t.ex. SensorReading(sensorName=…, value=…, timestamp=…).
    3. Sensor::Sensor(name) initierar medlemsvariabeln name.
        ○ Sensor::getName() returnerar namnet.
        ○ Sensor::read() ska skapa ett SensorReading‑objekt med dummyvärde
(t.ex. 42.0) och timestamp (t.ex. "2025‑10‑28 14:35") och returnera det.
4. Logger::log(reading, sensorName) ska skriva ut både sensorName och
reading.print().
I main.cpp, ersätt tidigare kod eller lägg till efter Device‑delen:
void foo() {
Sensor s("TemperatureSensor");
Logger l;
SensorReading r = s.read();
l.log(r, s.getName());
}
int main() {
// tidigare kod…
foo();
return 0;
}
5. Kör och verifiera att utskriften är begriplig och fungerar.
Block 3 – Design från kravspecifikation (utan arv)
Övning 3A – Luftkvalitetssystem
Scenario:
Du ska bygga ett system som övervakar luftkvalitet i ett rum med flera sensorer och kan
samla och logga alla mätvärden.
Krav:
● Klass AirSensor: har namn och metod read() som returnerar SensorReading.
● Klass AirMonitor: har en lista (std::vector<AirSensor>) med sensorer och
metod logAll() som anropar varje sensors read() och loggar resultat.
Uppgifter:
1. Skapa filerna AirSensor.h, AirSensor.cpp, AirMonitor.h,
AirMonitor.cpp.
2. AirSensor liknar Sensor från övning 2 men med eget namn.
3. AirMonitor ska ha konstruktor som tar en std::vector<AirSensor> eller
möjlighet att lägga till sensorer.
4. AirMonitor::logAll() ska iterera över sensorer, anropa read() och använda
Logger‑klass (från övning 2) för att logga.
5. I main.cpp, skapa t.ex. tre AirSensor‑objekt med olika namn, placera dem i en
AirMonitor, och anropa logAll(). Verifiera att alla sensorvärden loggas.
Övning 3B – Parkeringssystem
Scenario:
Ett parkeringshus ska kunna hantera bilar, lägga till och ta bort, samt skriva ut status.
Krav:
Car (struct):
struct Car {
std::string regNumber;
std::string arrivalTime;
void print() const;
};
●
ParkingHouse (klass):
class ParkingHouse {
private:
std::vector<Car> cars;
public:
void addCar(const Car& car);
bool removeCar(const std::string& regNumber);
void printStatus() const;
};
●
Uppgifter:
1. Skapa Car.h, Car.cpp and ParkingHouse.h, ParkingHouse.cpp.
2. Car::print() skriver ut t.ex. Car(reg=…, arrival=…).
3. ParkingHouse::addCar() lägger till bilen i vektorn.
ParkingHouse::removeCar() söker efter registreringsnummer och tar bort bilen
om den finns, returnerar true/false.
ParkingHouse::printStatus() skriver ut alla parkerade bilar.
4. I main.cpp, efter tidigare kod eller separat block:
○ Skapa några Car‑objekt.
○ Använd ParkingHouse för att lägga till dem.
○ Kalla printStatus().
○ Ta bort en bil via removeCar().
○ Kalla printStatus() igen och verifiera förändringar.
Block 4 – Reflektion och fördjupning
Diskussionsfrågor:
● Vad är skillnaden mellan struct och class i C++?
● Hur hjälpte .h/.cpp‑struktur dig att organisera koden?
● Varför är det bra att separera deklaration och implementation?
● Hur använder du komposition i dina lösningar (exempel: AirMonitor med
AirSensor, ParkingHouse med Car)?
● Vad var lätt och vad var utmanande idag?
Frivilliga extrauppgifter:
● Lägg till input från användaren: använd std::cin för att skapa nya Car eller nya
Sensor.
● Lägg till felhantering: t.ex. ogiltigt registreringsnummer, sensorvärde utanför förväntat
intervall.
● Skriv en enkel enhetstest‑funktion (t.ex. assert) som testar Sensor::read() eller
ParkingHouse::removeCar().
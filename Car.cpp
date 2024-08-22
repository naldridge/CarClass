//Car.cpp is the Car class function implementation file.
#include "Car.h"
#include <string>
using namespace std;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::buildInfo                                            +
  + Default constructor for prototype. Requires parameters for tank size and fuel economy.   +
  + Defaults fuel in tank and odometer reading to 0.                                         +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Car::buildInfo(int tankSize, int fuelEconomy, string name) {
  FuelTankSize = tankSize;
  MilesPerGallon = fuelEconomy;
  ModelName = name;
  FuelInTank = 0;
  Odometer = 0;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::setFuelInTank                                        +
  + Takes 2 parameters, gas is the value to add or remove from tank. If valid input, returns +
  + true then checks the bool parameter to add or subtract from tank. If not, returns false. +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Car::setFuelInTank(float gas) {
  FuelInTank = gas;
  return;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::setOdometer                                          +
  + Checks if miles is a valid input, if true then adds miles to Odometer. If false remains  +
  + unchanged and returns false                                                              +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Car::setOdometer(int miles) {
  Odometer += miles;
  return;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::getName                                              +
  + Returns the Model Name string value      .                                               +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
string Car::getName() const {
  return ModelName;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::getFuelInTank                                        +
  + Returns the value of the fuel in the tank.                                               +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
float Car::getFuelInTank() const {
  return FuelInTank;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::getOdometer                                          +
  + Returns the value of the odometer.                                                       +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
float Car::getOdometer() const {
  return Odometer;
}


int Car::getFuelTankSize() const {
  return FuelTankSize;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::getMilesPerGallon                                    +
  + Returns the value of the fuel economy.                                                   +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int Car::getMilesPerGallon() const {
  return MilesPerGallon;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::driveCar                                             +
  + Intakes miles driven. If input value is not a valid input, returns 0 value. If input is  +
  + valid and miles driven is less than the gas in the tank, returns 1 value and updates the +
  + gas tank value and odometer value. If the input is valid and the miles driven exceeds    +
  + the gas in the tank the odometer registers the amount of miles driven before running out +
  + of gas and the gas tank registers as empty, while returning 2 value.                     +
  + A complete fail due inappropriate data type will return a 3 value.                       +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int Car::driveCar(float miles) {
  bool validData = (miles > 0) ? true : false;
  int returnValue = 0;
  int fuelEconomy = getMilesPerGallon();
  float fuelLevel = getFuelInTank();
  float burned;

  if ((validData) && (miles <= fuelEconomy * fuelLevel)) {
    burned = miles / fuelEconomy;
    fuelLevel -= burned;
    setFuelInTank(fuelLevel);
    setOdometer(miles);
    returnValue = 1;
  } else if ((validData) && (miles >= fuelEconomy * fuelLevel)) {
    burned = fuelEconomy * fuelLevel;
    setFuelInTank(0);
    setOdometer(burned);
    returnValue = 2;
  } else {
    returnValue = 3;
  }

  return returnValue;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                Car::addFuel                                              +
  + Intakes gas pumped. If input value is not a valid input, returns 0 value. If input is    +
  + valid will not overfill tank, returns 1 value and updates the fuel in tank with the added+
  + gas amount. If the input value exceeds the space in the tank, the gas added will cut off +
  + at the maximum amount allowed in the gas tank and a return value of 2.                   +
  + A complete fail due inappropriate data type will return a 3 value.                       +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
int Car::addFuel(float gas) {
  bool validData = (gas > 0) ? true : false;
  int returnValue = 0;
  float fuelLevel = getFuelInTank();
  float tankSize = getFuelTankSize();

  if ((validData) && (gas <= tankSize - fuelLevel)) {
    fuelLevel = fuelLevel + gas;
    setFuelInTank(fuelLevel);
    returnValue = 1;
  } else if ((validData) && (gas >= tankSize - fuelLevel)) {
    setFuelInTank(tankSize);
    returnValue = 2;
  } else {
    returnValue = 3;
  }

  return returnValue;
}
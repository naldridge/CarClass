//Car.h is the Car class specification file.
#ifndef CAR_H
#define CAR_H

/*Name	your	class	Car	and	contain the	following	attributes:
• Miles Per Gallon
• Odometer
• Fuel in Tank
• Fuel Tank Size*/
class Car {
    private:
                float FuelInTank, Odometer;
                int MilesPerGallon, FuelTankSize;
    public:
                /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                  +                                Car Class Constructor:                                    +
                  + Intakes gas tank size and fuel economy and sets fuel level and odometer to 0 by default. +
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
                // Prototype
                void buildInfo(int tanksize, int fuelEconomy);
                ~Car() {
                }

               void setFuelInTank(float);
               void setOdometer(int);
               float getFuelInTank() const;
               float getOdometer() const;
               int getFuelTankSize() const;
               int getMilesPerGallon() const;
               int driveCar(float);
               int addFuel(float);

};


#endif
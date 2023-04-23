#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle
{

    public:

        void printInfo();

        void setDriverLastName(string name);
        void setLicensePlate(string plate);
        void setColor(string color);

        string getDriversLastName();
        string getLicensePlate();
        string getColor();

    private:
        string driverLastName;
        string licensePlate;
        string color;
};

#endif
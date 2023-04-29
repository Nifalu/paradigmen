#include "Car.h"

using namespace std;

string driversLastName;
string licensePlate;
string color;

void Car::printInfo()
{
    cout << "--- CAR INFO ---" << endl;
    cout << "Driver: " << this->driverLastName << endl;
    cout << "Plate: " << this->licensePlate << endl;
    cout << "Color: " << this->color <<  endl;
    cout << "Producer: " << this->getProducer() << endl;
    cout << "Type: " << this->getType() << endl;
    cout << "-----------------" << endl;
}

void Car::setDriverLastName(string name)
{
    this->driverLastName = name;
}

void Car::setLicensePlate(string plate)
{
    this->licensePlate = plate;
}

void Car::setColor(string col)
{
    this->color = col;
}

string Car::getDriversLastName()
{
    return this->driverLastName;
}

string Car::getLicensePlate()
{
    return this->licensePlate;
}

string Car::getColor()
{
    return this->color;
}



int main() {

    Car* testCar = new Car();
    testCar->setDriverLastName("Torvalds");
    testCar->setLicensePlate("Mr. Linux, DAD OF 3, KING OF GEEKS");
    testCar->setColor("Yellow");
    testCar->setProducer("Mercedes Benz");
    testCar->setType("SLK");

    testCar->printInfo();

    return 0;
}
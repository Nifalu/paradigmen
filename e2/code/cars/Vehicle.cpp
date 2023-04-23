#include "Vehicle.h"

using namespace std;


string producer;
string type;


void Vehicle::setProducer(string p)
{
    this->producer = p;
}

void Vehicle::setType(string t)
{
    this->type = t;
}

string Vehicle::getProducer()
{
    return this->producer;
}

string Vehicle::getType()
{
    return this->type;
}
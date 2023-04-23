#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using namespace std;

class Vehicle
{
    public:
        void setProducer(string p);
        void setType(string t);
        string getProducer();
        string getType();

    private:
        string producer;
        string type;
};

#endif
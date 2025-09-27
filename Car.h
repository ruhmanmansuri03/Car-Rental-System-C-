#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
private:
    string maker;
    string model;
    int year;
    string licensePlate;
    int rentPerDay;
    bool isAvailable;

public:
    Car(string maker, string model, int year, string licensePlate, int rentPerDay, bool isAvailable);

    string getMaker() const;
    string getModel() const;
    int getYear() const;
    string getLicensePlate() const;
    int getRentalPricePerDay() const;
    bool getIsAvailable() const;
    void setAvailable(bool available);
};

#endif

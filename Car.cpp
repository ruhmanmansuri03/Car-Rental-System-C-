#include "Car.h"

Car::Car(string maker, string model, int year, string licensePlate, int rentPerDay, bool isAvailable) {
    this->maker = maker;
    this->model = model;
    this->year = year;
    this->licensePlate = licensePlate;
    this->rentPerDay = rentPerDay;
    this->isAvailable = isAvailable;
}

string Car::getMaker() const { return maker; }
string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
string Car::getLicensePlate() const { return licensePlate; }
int Car::getRentalPricePerDay() const { return rentPerDay; }
bool Car::getIsAvailable() const { return isAvailable; }
void Car::setAvailable(bool available) { isAvailable = available; }

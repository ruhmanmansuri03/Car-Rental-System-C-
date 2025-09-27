#include "Customer.h"

Customer::Customer(string name, string contactNumber, string drivingLicenseNumber) {
    this->name = name;
    this->contactNumber = contactNumber;
    this->drivingLicenseNumber = drivingLicenseNumber;
}

string Customer::getName() const { return name; }
string Customer::getContactNumber() const { return contactNumber; }
string Customer::getDrivingLicenseNumber() const { return drivingLicenseNumber; }

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string name;
    string contactNumber;
    string drivingLicenseNumber;

public:
    Customer(string name, string contactNumber, string drivingLicenseNumber);

    string getName() const;
    string getContactNumber() const;
    string getDrivingLicenseNumber() const;
};

#endif

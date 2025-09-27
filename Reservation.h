#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Car.h"
#include "Customer.h"
using namespace std;

class Reservation {
private:
    string reservationId;
    Car car;
    Customer customer;
    int startDate;
    int endDate;
    double totalPrice;

public:
    Reservation(string reservationId, Car car, Customer customer, int startDate, int endDate, double totalPrice);

    string getReservationId() const;
    Car getCar() const;
    Customer getCustomer() const;
    int getStartDate() const;
    int getEndDate() const;
    double getTotalPrice() const;
};

#endif

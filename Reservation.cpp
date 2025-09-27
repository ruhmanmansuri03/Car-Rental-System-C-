#include "Reservation.h"

Reservation::Reservation(string reservationId, Car car, Customer customer, int startDate, int endDate, double totalPrice)
    : reservationId(reservationId), car(car), customer(customer), startDate(startDate), endDate(endDate), totalPrice(totalPrice) {}

string Reservation::getReservationId() const { return reservationId; }
Car Reservation::getCar() const { return car; }
Customer Reservation::getCustomer() const { return customer; }
int Reservation::getStartDate() const { return startDate; }
int Reservation::getEndDate() const { return endDate; }
double Reservation::getTotalPrice() const { return totalPrice; }

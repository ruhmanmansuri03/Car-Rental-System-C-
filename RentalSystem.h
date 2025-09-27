#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <map>
#include <vector>
#include "Car.h"
#include "Customer.h"
#include "Reservation.h"
#include "PaymentProcessor.h"
#include "CreditCardPaymentProcessor.h"

class RentalSystem {
private:
    map<string, Car> cars;
    map<string, Reservation*> reservations;
    PaymentProcessor* paymentProcessor;

    bool isCarAvailable(const Car& car, int startDate, int endDate);
    string generateReservationID();

public:
    RentalSystem();
    ~RentalSystem();

    void addCar(Car car);
    void removeCar(string licensePlate);
    vector<Car> searchCars(string maker, string model, int startDate, int endDate);
    Reservation* makeReservation(Customer customer, Car car, int startDate, int endDate);
    void cancelReservation(string reservationId);
    bool processPayment(Reservation& reservation);
};

#endif

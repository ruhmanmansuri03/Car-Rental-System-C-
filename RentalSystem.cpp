#include "RentalSystem.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>

RentalSystem::RentalSystem() {
    paymentProcessor = new CreditCardPaymentProcessor();
}

RentalSystem::~RentalSystem() {
    delete paymentProcessor;
    for (auto& entry : reservations) {
        delete entry.second;
    }
}

void RentalSystem::addCar(Car car) {
    cars[car.getLicensePlate()] = car;
    cout << "Car added successfully" << endl;
}

void RentalSystem::removeCar(string licensePlate) {
    cars.erase(licensePlate);
}

vector<Car> RentalSystem::searchCars(string maker, string model, int startDate, int endDate) {
    vector<Car> availableCars;
    for (auto& entry : cars) {
        Car car = entry.second;
        if (car.getMaker() == maker && car.getModel() == model && car.getIsAvailable()) {
            if (isCarAvailable(car, startDate, endDate)) {
                availableCars.push_back(car);
            }
        }
    }
    return availableCars;
}

bool RentalSystem::isCarAvailable(const Car& car, int startDate, int endDate) {
    for (auto& entry : reservations) {
        Reservation* reservation = entry.second;
        if (reservation->getCar().getLicensePlate() == car.getLicensePlate()) {
            if (startDate < reservation->getEndDate() && endDate > reservation->getStartDate()) {
                return false;
            }
        }
    }
    return true;
}

Reservation* RentalSystem::makeReservation(Customer customer, Car car, int startDate, int endDate) {
    if (isCarAvailable(car, startDate, endDate)) {
        string reservationId = generateReservationID();
        double totalPrice = car.getRentalPricePerDay() * (endDate - startDate);
        Reservation* reservation = new Reservation(reservationId, car, customer, startDate, endDate, totalPrice);
        reservations[reservationId] = reservation;
        cars[car.getLicensePlate()].setAvailable(false);
        return reservation;
    }
    return nullptr;
}

void RentalSystem::cancelReservation(string reservationId) {
    if (reservations.find(reservationId) != reservations.end()) {
        reservations[reservationId]->getCar().setAvailable(true);
        delete reservations[reservationId];
        reservations.erase(reservationId);
    }
}

bool RentalSystem::processPayment(Reservation& reservation) {
    return paymentProcessor->processPayment(reservation.getTotalPrice());
}

string RentalSystem::generateReservationID() {
    static int counter = 1;
    return "RES" + to_string(counter++);
}

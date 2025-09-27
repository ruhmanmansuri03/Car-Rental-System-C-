#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Car.h"
#include "Customer.h"
#include "Reservation.h"
#include "RentalSystem.h"

using namespace std;

int main() {
    cout << "Car Rental System" << endl;

    RentalSystem rentalSystem;

    Car car1("Toyota", "Glanza", 2022, "ABCD1234", 600, true);
    Car car2("Honda", "Civic", 2021, "DEFG5678", 800, true);
    Car car3("Ford", "Mustang", 2023, "HIJK8973", 1200, true);

    rentalSystem.addCar(car1);
    rentalSystem.addCar(car2);
    rentalSystem.addCar(car3);

    // Create customer
    Customer customer("Kanika", "9054678321", "DL1234");

    // For demo: simulate rental period (just int days)
    int startDate = 0;  // today
    int endDate = 3;    // 3 days later

    vector<Car> availableCars = rentalSystem.searchCars("Toyota", "Glanza", startDate, endDate);

    if (!availableCars.empty()) {
        Car selectedCar = availableCars[0];
        Reservation* reservation = rentalSystem.makeReservation(customer, selectedCar, startDate, endDate);
        if (reservation != nullptr) {
            bool isPaymentSuccessful = rentalSystem.processPayment(*reservation);
            if (isPaymentSuccessful) {
                cout << "Reservation successful with Reservation ID: " << reservation->getReservationId() << endl;
            } else {
                cout << "Reservation failed, Reservation cancelled: " << reservation->getReservationId() << endl;
                rentalSystem.cancelReservation(reservation->getReservationId());
            }
        } else {
            cout << "Selected car not available for given dates" << endl;
        }
    } else {
        cout << "No car available for given specification" << endl;
    }

    return 0;
}

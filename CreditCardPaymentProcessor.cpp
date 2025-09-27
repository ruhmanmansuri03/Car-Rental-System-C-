#include "CreditCardPaymentProcessor.h"

bool CreditCardPaymentProcessor::processPayment(double amount) {
    cout << "Amount " << amount << " processed successfully through Credit Card" << endl;
    return true;
}

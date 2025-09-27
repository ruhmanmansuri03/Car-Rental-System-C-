#include "PayPalPaymentProcessor.h"

bool PayPalPaymentProcessor::processPayment(double amount) {
    cout << "Amount " << amount << " processed successfully through PayPal" << endl;
    return true;
}

#ifndef PAYPALPAYMENTPROCESSOR_H
#define PAYPALPAYMENTPROCESSOR_H

#include "PaymentProcessor.h"
#include <iostream>
using namespace std;

class PayPalPaymentProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override;
};

#endif

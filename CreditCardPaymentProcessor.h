#ifndef CREDITCARDPAYMENTPROCESSOR_H
#define CREDITCARDPAYMENTPROCESSOR_H

#include "PaymentProcessor.h"
#include <iostream>
using namespace std;

class CreditCardPaymentProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override;
};

#endif

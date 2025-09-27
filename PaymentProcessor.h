#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

class PaymentProcessor {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentProcessor() {}
};

#endif

#ifndef invoice_h
#define invoice_h

#include "../../domain/invoice/buy-register.hpp"

class Invoice
{
private:
    vector<BuyRegister> _buyRegisters;

public:
    Invoice();
    void addRegister(BuyRegister *buyRegister);
    string toString();
};

#endif
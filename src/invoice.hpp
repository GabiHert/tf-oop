#ifndef invoice_h
#define invoice_h
//#pragma once

#include "buy-register.hpp"
#include "company-model.hpp"

class Invoice
{
private:
    vector<BuyRegister *> *_buyRegisters;
    CompanyModel *_companyModel;
    float _totalPrice;

public:
    Invoice(vector<BuyRegister *> *buyRegisters, CompanyModel *companyModel);
    void addRegister(BuyRegister *buyRegister);
    string toString();
    float getTotalPrice() { return this->_totalPrice; }
};

#endif
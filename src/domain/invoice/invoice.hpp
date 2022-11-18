#ifndef invoice_h
#define invoice_h

#include "../../domain/invoice/buy-register.hpp"
#include "../../domain/model/company-model.hpp"

class Invoice
{
private:
    vector<BuyRegister *> _buyRegisters;
    CompanyModel *_companyModel;
    float _totalPrice;

public:
    Invoice(){};
    Invoice(vector<BuyRegister *> buyRegisters, CompanyModel *companyModel);
    void addRegister(BuyRegister *buyRegister);
    string toString();
    float getTotalPrice() { return this->_totalPrice; }
};

#endif
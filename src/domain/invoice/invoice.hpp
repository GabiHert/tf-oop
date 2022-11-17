#ifndef invoice_h
#define invoice_h

#include "../../domain/invoice/buy-register.hpp"
#include "../../domain/model/company-model.hpp"

class Invoice
{
private:
    vector<BuyRegister *> _buyRegisters;
    CompanyModel *_companyModel;

public:
    Invoice(){};
    Invoice(vector<BuyRegister *> buyRegisters, CompanyModel *companyModel);
    void addRegister(BuyRegister *buyRegister);
    string toString();
};

#endif
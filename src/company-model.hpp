

#ifndef company_model_h
#define company_model_h
//#pragma once

#include <string>
#include "company-dto.hpp"
#include "./address-model.hpp"
using namespace std;
class CompanyModel
{
private:
    string _name;
    string _cnpj;
    string _stateSub;
    AddressModel *_addressModel;

public:
    CompanyModel(CompanyDto *companyDto);
    string getName() { return _name; }
    string getCnpj() { return _cnpj; }
    string getStateSub() { return _stateSub; }
    AddressModel *getAddressModel() { return _addressModel; }
    string toString();
};

#endif
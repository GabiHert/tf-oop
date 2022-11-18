#include <string>
#include "../../domain/dto/company-dto.hpp"
#include "./address-model.hpp"
using namespace std;

#ifndef company_model_h
#define company_model_h

class CompanyModel
{
private:
    string _name;
    string _cnpj;
    string _stateSub;
    AddressModel *_addressModel;

public:
    CompanyModel(){};
    CompanyModel(CompanyDto *companyDto);
    string getName() { return _name; }
    string getCnpj() { return _cnpj; }
    string getStateSub() { return _stateSub; }
    AddressModel *getAddressModel() { return _addressModel; }
};

#endif
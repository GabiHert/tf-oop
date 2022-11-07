#include <string>
#include "domain/dto/company-dto.hpp"
using namespace std;

#ifndef company_model_h
#define company_model_h

class CompanyModel
{
private:
    string _name;
    string _cnpj;
    string _stateSub;
    string _address;

public:
    CompanyModel(CompanyDto *companyDto);
    string getName() const { return _name; }
    string getCnpj() const { return _cnpj; }
    string getStateSub() const { return _stateSub; }
    string getAddress() const { return _address; }
};

#endif
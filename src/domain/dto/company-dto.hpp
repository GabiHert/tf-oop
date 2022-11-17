#include <string>
#include <vector>
#include "./address-dto.hpp"
using namespace std;

#ifndef company_sto_h
#define company_sto_h

class CompanyDto
{
private:
    string _name;
    string _cnpj;
    string _stateSub;
    AddressDto *_addressDto;

public:
    CompanyDto(string name, string cnpj, string stateSub, AddressDto *addressDto);
    string getName() const { return _name; }
    string getCnpj() const { return _cnpj; }
    string getStateSub() const { return _stateSub; }
    AddressDto *getAddressDto() const { return _addressDto; }
};

#endif
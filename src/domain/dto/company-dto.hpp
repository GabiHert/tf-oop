#include <string>
#include <vector>
using namespace std;

#ifndef company_sto_h
#define company_sto_h

class CompanyDto
{
private:
    string _name;
    string _cnpj;
    string _stateSub;
    string _address;

public:
    CompanyDto(string name, string cnpj, string stateSub, string address);
    string getName() const { return _name; }
    string getCnpj() const { return _cnpj; }
    string getStateSub() const { return _stateSub; }
    string getAddress() const { return _address; }
};

#endif
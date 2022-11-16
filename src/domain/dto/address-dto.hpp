#include <string>
#include <vector>
using namespace std;

#ifndef address_dto_h
#define address_dto_h

class AddressDto
{
private:
    string _publicPlace;
    string _number;
    string _complement;
    string _district;
    string _city;
    string _federationUnit;
    string _cep;

public:
    AddressDto(string publicPlace, string number, string complement, string district, string city, string federationUnit, string cep);

    string getPublicPlace() const { return _publicPlace; }

    string getNumber() const { return _number; }

    string getComplement() const { return _complement; }

    string getDistrict() const { return _district; }

    string getCity() const { return _city; }

    string getFederationUnit() const { return _federationUnit; }

    string getCep() const { return _cep; }
};

#endif
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
    string _phoneNumber;

public:
    AddressDto(){};
    AddressDto(string publicPlace, string number, string complement, string district, string city, string federationUnit, string cep, string phoneNumber);

    string getPhoneNumber() { return _phoneNumber; }
    string getPublicPlace() { return _publicPlace; }

    string getNumber() { return _number; }

    string getComplement() { return _complement; }

    string getDistrict() { return _district; }

    string getCity() { return _city; }

    string getFederationUnit() { return _federationUnit; }

    string getCep() { return _cep; }
};

#endif
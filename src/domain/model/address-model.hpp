#include <string>
#include "../dto/address-dto.hpp"
using namespace std;

#ifndef address_model_h
#define address_model_h

class AddressModel
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
    AddressModel() {}
    AddressModel(AddressDto *addressDto);

    string getPublicPlace() { return _publicPlace; }

    string getNumber() { return _number; }

    string getComplement() { return _complement; }

    string getDistrict() { return _district; }

    string getCity() { return _city; }

    string getFederationUnit() { return _federationUnit; }

    string getCep() { return _cep; }

    string getPhoneNumber() { return _phoneNumber; }
};

#endif
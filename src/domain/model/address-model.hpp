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

public:
    AddressModel(AddressDto *addressDto);

    string getPublicPlace() const { return _publicPlace; }

    string getNumber() const { return _number; }

    string getComplement() const { return _complement; }

    string getDistrict() const { return _district; }

    string getCity() const { return _city; }

    string getFederationUnit() const { return _federationUnit; }

    string getCep() const { return _cep; }
};

#endif
#include "address-model.hpp"
#include <sstream>
AddressModel::AddressModel(AddressDto *addressDto)
{
    this->_publicPlace = addressDto->getPublicPlace();
    this->_number = addressDto->getNumber();
    this->_complement = addressDto->getComplement();
    this->_district = addressDto->getDistrict();
    this->_city = addressDto->getCity();
    this->_federationUnit = addressDto->getFederationUnit();
    this->_cep = addressDto->getCep();
    this->_phoneNumber = addressDto->getPhoneNumber();
}

string AddressModel::toString()
{

    stringstream stream;

    stream << "AddressModel: " << endl;
    stream << " _publicPlace: " << this->_publicPlace << endl;
    stream << " _number: " << this->_number << endl;
    stream << " _complement: " << this->_complement << endl;
    stream << " _district: " << this->_district << endl;
    stream << " _city: " << this->_city << endl;
    stream << " _federationUnit: " << this->_federationUnit << endl;
    stream << " _cep: " << this->_cep << endl;
    stream << " _phoneNumber: " << this->_phoneNumber << endl;

    return stream.str();
}
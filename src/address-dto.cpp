#include "address-dto.hpp"
#include <sstream>

AddressDto::AddressDto(string publicPlace, string number, string complement, string district, string city, string federationUnit, string cep, string phoneNumber)
{
    this->_publicPlace = publicPlace;
    this->_number = number;
    this->_complement = complement;
    this->_district = district;
    this->_city = city;
    this->_federationUnit = federationUnit;
    this->_cep = cep;
    this->_phoneNumber = phoneNumber;
}

string AddressDto::toString()
{

    stringstream stream;

    stream << "AddressDto: " << endl;
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
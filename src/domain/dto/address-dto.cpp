#include "address-dto.hpp"
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

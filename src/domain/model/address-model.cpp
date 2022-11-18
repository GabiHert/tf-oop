#include "./address-model.hpp"
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

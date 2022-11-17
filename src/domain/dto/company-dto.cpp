#include "./company-dto.hpp"

CompanyDto::CompanyDto(string name, string cnpj, string stateSub, AddressDto *addressDto)
{
    this->_name = name;
    this->_cnpj = cnpj;
    this->_stateSub = stateSub;
    this->_addressDto = addressDto;
};

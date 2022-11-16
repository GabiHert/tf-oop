#include "./company-dto.hpp"

CompanyDto::CompanyDto(string name, string cnpj, string stateSub, string address)
{
    this->_name = name;
    this->_cnpj = cnpj;
    this->_stateSub = stateSub;
    this->_address = address;
};

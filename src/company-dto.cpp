#include "./company-dto.hpp"
#include <sstream>

CompanyDto::CompanyDto(string name, string cnpj, string stateSub, AddressDto *addressDto)
{
    this->_name = name;
    this->_cnpj = cnpj;
    this->_stateSub = stateSub;
    this->_addressDto = addressDto;
};
string CompanyDto::toString()
{

    stringstream stream;

    stream << "CompanyDto: " << endl;
    stream << " _addressModel: " << this->_addressDto->toString() << endl;
    stream << " _name: " << this->_name << endl;
    stream << " _cnpj: " << this->_cnpj << endl;
    stream << " _stateSub: " << this->_stateSub << endl;

    return stream.str();
}

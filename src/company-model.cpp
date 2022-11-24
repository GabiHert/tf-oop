#include "./company-model.hpp"
#include <sstream>

CompanyModel::CompanyModel(CompanyDto *companyDto)
{
    this->_addressModel = new AddressModel(companyDto->getAddressDto());
    this->_name = companyDto->getName();
    this->_cnpj = companyDto->getCnpj();
    this->_stateSub = companyDto->getStateSub();
}

string CompanyModel::toString()
{

    stringstream stream;

    stream << "CompanyModel: " << endl;
    stream << " _addressModel: " << this->_addressModel << endl;
    stream << " _name: " << this->_name << endl;
    stream << " _cnpj: " << this->_cnpj << endl;
    stream << " _stateSub: " << this->_stateSub << endl;

    return stream.str();
}

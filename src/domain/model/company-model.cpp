#include "./company-model.hpp"

CompanyModel::CompanyModel(CompanyDto *companyDto)
{
    this->_addressModel = new AddressModel(companyDto->getAddressDto());
    this->_name = companyDto->getName();
    this->_cnpj = companyDto->getCnpj();
    this->_stateSub = companyDto->getStateSub();
}

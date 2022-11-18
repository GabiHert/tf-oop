#include "./invoice.hpp"

Invoice::Invoice(vector<BuyRegister *> buyRegisters, CompanyModel *companyModel)
{
    this->_buyRegisters = buyRegisters;

    for (int i = 0; i < this->_buyRegisters.size(); i++)
    {
        this->_totalPrice += this->_buyRegisters[i]->getPrice();
    }
}

void Invoice::addRegister(BuyRegister *buyRegister)
{
    this->_buyRegisters.push_back(buyRegister);
    this->_totalPrice += buyRegister->getPrice();
};

string format(string aux, unsigned int length)
{
    int spaces = (aux.length() - length) / 2;
    string spacesStr;

    while (spaces > 0)
    {
        spacesStr += " ";
        spaces--;
    }

    return spacesStr + aux + spacesStr;
}

string Invoice::toString()
{
    vector<string> invoice;
    string line;
    for (int i = 0; i < 80; i++)
        line += "-";

    invoice.push_back(line);

    string aux;
    aux = this->_companyModel->getName() + " - " + "Telefone: " + this->_companyModel->getAddressModel()->getPhoneNumber();
    invoice.push_back(format(aux, 80));

    aux = this->_companyModel->getAddressModel()->getPublicPlace() + ", " + this->_companyModel->getAddressModel()->getNumber() + " - " + this->_companyModel->getAddressModel()->getDistrict() + " - " + this->_companyModel->getAddressModel()->getCity() + "-" + this->_companyModel->getAddressModel()->getFederationUnit() + " CEP " + this->_companyModel->getAddressModel()->getCep();
    invoice.push_back(format(aux, 80));

    invoice.push_back(line);

    invoice.push_back(format("DOCUMENTO AUXILIAR DA NOTA FISCAL DE CONSUMIDOR ELETRÔNICA", 80));

    invoice.push_back(line);

    invoice.push_back(format("I. CÓDIGO         DESCRIÇÃO                           R$ UN QTD  DESCONTO VAL(R$)", 80));

    invoice.push_back(line);

    // todo: buys

    invoice.push_back(line);

    // 11
    string spaces = "           ";
    string total = to_string(this->getTotalPrice());
    aux = "TOTAL" + spaces.substr(total.length()) + total;

    invoice.push_back("                                                                " + aux);
    invoice.push_back(line);
}

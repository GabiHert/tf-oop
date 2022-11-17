#include "./invoice.hpp"

Invoice::Invoice(vector<BuyRegister *> buyRegisters,CompanyModel *companyModel)
{
    this->_buyRegisters = buyRegisters;
}

void Invoice::addRegister(BuyRegister *buyRegister)
{
    this->_buyRegisters.push_back(buyRegister);
};

string Invoice::toString()
{
    vector<string> invoice;
    string line;
    for (int i = 0; i < 80; i++)
    {
        line += "-";
    }

    invoice.push_back(line);

    string firstLine = this->_companyModel->getName()+" - "+"Telefone: " + this->_companyModel->getAddress();
}

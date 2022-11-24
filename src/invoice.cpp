#include "./invoice.hpp"
#include <iostream>
#include "utils.hpp"
#include <iomanip>
#include <ctime>

using namespace std;
Invoice::Invoice(vector<BuyRegister *> *buyRegisters, CompanyModel *companyModel)
{
    cout << "Invoice::Invoice - Process started - buyRegisters size: " << buyRegisters->size() << endl;
    this->_buyRegisters = buyRegisters;
    this->_companyModel = companyModel;
    this->_totalPrice = 0;

    for (int i = 0; i < int(this->_buyRegisters->size()); i++)
    {
        cout << "Invoice::Invoice - : buyRegister" << buyRegisters->at(i)->toString() << endl;
        this->_totalPrice = this->_buyRegisters->at(i)->getPrice() + this->_totalPrice;
    }
}

void Invoice::addRegister(BuyRegister *buyRegister)
{
    this->_buyRegisters->push_back(buyRegister);
    this->_totalPrice += buyRegister->getPrice();
};

string format(string aux, int length)
{
    cout << "format - Process started -  length : " << length << " aux: " << aux << "aux length : " << aux.length() << endl;

    int spaces = (length - aux.length()) / 2;
    cout << "format - spaces: " << spaces << endl;

    string spacesStr;

    while (spaces > 0)
    {
        spacesStr += " ";
        spaces--;
    }
    cout << "format - Process finished" << endl;

    return spacesStr + aux + spacesStr;
}

string Invoice::toString()
{
    cout << "Invoice::toString - Process started" << endl;

    stringstream invoice;
    string line;
    for (int i = 0; i < 85; i++)
        line += "-";

    invoice << (line) << endl;
    string aux;
    aux = this->_companyModel->getName() + " - " + "Telefone: " + this->_companyModel->getAddressModel()->getPhoneNumber();
    invoice << (format(aux, 85)) << endl;
    aux = this->_companyModel->getAddressModel()->getPublicPlace() + ", " + this->_companyModel->getAddressModel()->getNumber() + " - " + this->_companyModel->getAddressModel()->getDistrict() + " - " + this->_companyModel->getAddressModel()->getCity() + "-" + this->_companyModel->getAddressModel()->getFederationUnit() + " CEP " + this->_companyModel->getAddressModel()->getCep();
    invoice << (format(aux, 85)) << endl;
    invoice << (line) << endl;
    invoice << (format("DOCUMENTO AUXILIAR DA NOTA FISCAL DE CONSUMIDOR ELETRÔNICA", 85)) << endl;
    invoice << (line) << endl;
    invoice << (format("I. CODIGO" + strSpaceGen(8) + "DESCRICAO" + strSpaceGen(22) + "R$   UN       QTD DESCONTO   VAL(R$)", 85)) << endl;
    invoice << (line) << endl;

    for (int i = 0; i < int(this->_buyRegisters->size()); i++)
    {
        cout << "Invoice::toString - getting buyRegister " << i << " buyRegister - " << this->_buyRegisters->at(i)->toString() << endl;
        string start = (i + 1 > 9 ? to_string(i + 1) : "0" + to_string(i + 1));

        start += " " + this->_buyRegisters->at(i)->getBarCode() + " " + this->_buyRegisters->at(i)->getDescription();

        if (start.length() > 41)
            invoice << start << endl
                    << strSpaceGen(46);
        else
            invoice << start << strSpaceGen(46 - start.length());

        string unitPrice = truncFloatToStr(this->_buyRegisters->at(i)->getUnitPrice(), 2);
        if (unitPrice.length() > 6)
        {
            invoice << unitPrice << endl
                    << strSpaceGen(52);
        }
        else
        {
            invoice << strSpaceGen(6 - unitPrice.length()) << unitPrice;
        }

        string sellAmount = this->_buyRegisters->at(i)->getSellAmount()->getName();

        if (sellAmount.length() < 7)
        {
            sellAmount = strSpaceGen(7 - sellAmount.length()) + sellAmount;
        }

        invoice << " " << sellAmount;

        string amount = truncFloatToStr(this->_buyRegisters->at(i)->getUnits(), 2);
        if (amount.length() < 6)
        {
            invoice << strSpaceGen(7 - amount.length()) << amount;
        }
        else
        {
            invoice << " " << amount;
        }

        string discount = truncFloatToStr(this->_buyRegisters->at(i)->getDiscount(), 2);
        if (this->_buyRegisters->at(i)->getDiscount() > 0)
            discount = "-" + discount;
        else
            discount = " " + discount;

        invoice << " " << discount;

        string price = truncFloatToStr(this->_buyRegisters->at(i)->getPrice(), 2);
        if (price.length() < 6)
        {
            invoice << strSpaceGen(6 - price.length()) << price;
        }
        else
        {
            invoice << " " << price;
        }

        invoice << endl;
    }
    invoice << line << endl;

    string total = truncFloatToStr(this->getTotalPrice(), 2);

    invoice << strSpaceGen(69) + "TOTAL" + strSpaceGen(11).substr(total.length()) + total << endl;

    invoice << line << endl;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    invoice << "NFC-e: 123 - Serie: 45" << strSpaceGen(38) << "Data: " << put_time(&tm, "%d/%m/%Y %H:%M:%S") << endl;
    invoice << line << endl;

    cout << "Invoice::toString - Process finished" << endl;

    return invoice.str();
}

#include "./take-m-pay-n-discount.hpp"
#include <sstream>
#include <iostream>
using namespace std;

TakeMPayNDiscount::TakeMPayNDiscount(DiscountModel *discountModel)
{
    cout << "TakeMPayNDiscount::TakeMPayNDiscount - Process started" << endl;

    this->_barCode = discountModel->getField1();
    this->_amountToBeTook = discountModel->getField3();
    this->_amountToBePaid = discountModel->getField4();

    cout << "TakeMPayNDiscount::TakeMPayNDiscount - Process finished" << this->toString() << endl;
}

void TakeMPayNDiscount::apply(vector<BuyRegister *> *buyRegisters)
{
    cout << "TakeMPayNDiscount::apply - Process started" << endl;

    int i = 0;
    while (i < int(buyRegisters->size()) && buyRegisters->at(i)->getBarCode() != this->_barCode)
        i++;

    if (i < int(buyRegisters->size()) && buyRegisters->at(i)->getUnits() >= this->_amountToBeTook)
        buyRegisters->at(i)->addDiscount((buyRegisters->at(i)->getUnits() - this->_amountToBePaid) * buyRegisters->at(i)->getUnitPrice());
    else
        cout << "TakeMPayNDiscount::apply - No discount applied" << endl;

    cout << "TakeMPayNDiscount::apply - Process started" << endl;
};

string TakeMPayNDiscount::toString()
{

    stringstream stream;

    stream << "TakeMPayNDiscount: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _amountToBeTook: " << this->_amountToBeTook << endl;
    stream << " _amountToBePaid: " << this->_amountToBePaid << endl;

    return stream.str();
}
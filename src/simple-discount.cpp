#include "./simple-discount.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include "buy-register.hpp"
using namespace std;

SimpleDiscount::SimpleDiscount(DiscountModel *discountModel)
{
    cout << "SimpleDiscount::SimpleDiscount - Process started - " << discountModel->toString() << endl;
    this->_barCode = discountModel->getField1();
    this->_discount = discountModel->getField2();

    cout << "SimpleDiscount::SimpleDiscount - Process finished - " << this->toString() << endl;
}

void SimpleDiscount::apply(vector<BuyRegister *> *buyRegisters)
{
    cout << "SimpleDiscount::apply - Process started  " << endl;
    for (int i = 0; i < buyRegisters->size(); i++)
    {
        cout << buyRegisters->at(i)->getBarCode() << this->_barCode << endl;
        if (buyRegisters->at(i)->getBarCode() == this->_barCode)
        {
            cout << "SimpleDiscount::apply - adding discount  " << endl;

            buyRegisters->at(i)->addDiscount(this->_discount);
        }
    }
    cout << "SimpleDiscount::apply - Process finished " << endl;
}

string SimpleDiscount::toString()
{

    stringstream stream;

    stream << "SimpleDiscount: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _discount: " << this->_discount << endl;

    return stream.str();
}
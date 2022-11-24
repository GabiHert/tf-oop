#include "./combined-discount.hpp"
#include <sstream>
#include <iostream>
using namespace std;

CombinedDiscount::CombinedDiscount(DiscountModel *discountModel)
{
    cout << "CombinedDiscount::CombinedDiscount - Process started" << endl;

    this->_barCodeA = discountModel->getField1();
    this->_amountToBeTook = discountModel->getField3();
    this->_amountToBeApplied = discountModel->getField4();
    this->_barCodeB = discountModel->getField5();
    this->_discountPercentage = discountModel->getField6();

    cout << "CombinedDiscount::CombinedDiscount - Process finished - " << this->toString() << endl;
}

void CombinedDiscount::apply(vector<BuyRegister *> *buyRegisters)
{
    cout << "CombinedDiscount::apply - Process started" << endl;

    int productABuyRegisterIndex, productBBuyRegisterIndex;
    for (int i = 0; i < int(buyRegisters->size()); i++)
    {
        if (buyRegisters->at(i)->getBarCode() == this->_barCodeA)
            productABuyRegisterIndex = i;

        if (buyRegisters->at(i)->getBarCode() == this->_barCodeB)
            productBBuyRegisterIndex = i;
    }

    if (buyRegisters->at(productABuyRegisterIndex)->getUnits() >= this->_amountToBeTook)
    {
        for (int i = 0; (i < buyRegisters->at(productBBuyRegisterIndex)->getUnits()) && (i < this->getAmountToBeApplied()); i++)
        {
            cout << "CombinedDiscount::apply - adding discount - discountPercentage: " << this->_discountPercentage << " - UnitPrice: " << buyRegisters->at(productABuyRegisterIndex)->getUnitPrice() << " Total: " << this->_discountPercentage * buyRegisters->at(productABuyRegisterIndex)->getUnitPrice() << endl;
            buyRegisters->at(productBBuyRegisterIndex)->addDiscount(this->_discountPercentage * buyRegisters->at(productABuyRegisterIndex)->getUnitPrice());
        }
    }
    else
    {
        cout << "CombinedDiscount::apply - discount not suitable - amountToBeTook: " << this->_amountToBeTook << " amountTook: " << buyRegisters->at(productABuyRegisterIndex)->getUnits() << endl;
    }

    cout << "CombinedDiscount::apply - Process finished" << endl;
}

string CombinedDiscount::toString()
{

    stringstream stream;

    stream << "CombinedDiscount: " << endl;
    stream << " _barCodeA: " << this->_barCodeA << endl;
    stream << " _amountToBeTook: " << this->_amountToBeTook << endl;
    stream << " _amountToBeApplied: " << this->_amountToBeApplied << endl;
    stream << " _barCodeB: " << this->_barCodeB << endl;
    stream << " _discountPercentage: " << this->_discountPercentage << endl;

    return stream.str();
}

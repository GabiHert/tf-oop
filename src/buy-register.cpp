#include "./buy-register.hpp"
#include <sstream>
#include <iostream>
#include "sell-amount.hpp"
#include "buy-request-model.hpp"
using namespace std;

BuyRegister::BuyRegister(ProductModel *productModel, float units)
{
    cout << "BuyRegister::BuyRegister - Process started - units:" << units << "productModel: " << productModel->toString() << endl;

    this->_units = units;
    this->_barCode = productModel->getBarCode();
    this->_description = productModel->getDescription();
    this->_sellAmount = productModel->getSellAmount();
    this->_measurementUnit = productModel->getMeasurementUnit();
    this->_unitPrice = productModel->getUnitPrice();
    this->_price = this->_units * this->_unitPrice;
    this->_discount = 0;

    cout << "BuyRegister::BuyRegister - Process finished - " << this->toString() << endl;
}
void BuyRegister::addDiscount(float value)
{
    cout << "BuyRegister::addDiscount - Process started - value: " << value << endl;
    this->_discount = this->_discount > 0 ? this->_discount - value : this->_discount + value;
    cout << "BuyRegister::addDiscount - Process finished - discount: " << this->_discount << endl;
}

void BuyRegister::addUnits(float units)
{
    cout << "BuyRegister::addAmount - Process started - unitsToAdd: " << units << " units: " << this->_units << endl;
    this->_units += units;
    cout << "BuyRegister::addAmount - Process started - amount : " << this->_units << endl;
}
float BuyRegister::getUnits()
{
    return this->_units;
}

string BuyRegister::toString()
{

    stringstream stream;

    stream << "BuyRegister: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _units: " << this->getUnits() << endl;
    stream << " _description: " << this->_description << endl;
    stream << " _measurementUnit: " << this->_measurementUnit << endl;
    stream << " _unitPrice: " << this->_unitPrice << endl;
    stream << " _discount: " << this->_discount << endl;
    stream << " _price: " << this->_price << endl;
    stream << " _sellAmount: " << this->_sellAmount << endl;

    return stream.str();
}

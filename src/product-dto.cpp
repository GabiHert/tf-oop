

#include "./product-dto.hpp"
#include <sstream>
#include <iostream>
using namespace std;

ProductDto::ProductDto(string barCode, string description, string sellAmount, string measurementUnit, string amount, string unitPrice)
{
    this->_barCode = barCode;
    this->_description = description;
    this->_sellAmount = new SellAmount(sellAmount);
    this->_measurementUnit = measurementUnit;
    this->_amount = stof(amount);
    this->_unitPrice = stof(unitPrice);

    cout << "ProductDto::ProductDto - " << this->toString() << endl;
}

string ProductDto::toString()
{

    stringstream stream;
    stream.precision(2);
    stream << "ProductDto: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _amount: " << this->_amount << endl;
    stream << " _description: " << this->_description << endl;
    stream << " _measurementUnit: " << this->_measurementUnit << endl;
    stream << " _sellAmount: " << this->_sellAmount->getName() << endl;
    stream << " _unitPrice: " << this->_unitPrice << endl;

    return stream.str();
}

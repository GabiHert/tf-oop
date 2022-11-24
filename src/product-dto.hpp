#ifndef ProductDto_h
#define ProductDto_h
// #pragma once

#include <string>
#include <vector>
using namespace std;
#include "sell-amount.hpp"

class ProductDto
{
private:
    string _barCode;
    string _description;
    SellAmount *_sellAmount; // todo:unit or bulk
    string _measurementUnit;
    float _amount;
    float _unitPrice;

public:
    ProductDto(string barCode, string description, string sellAmount, string measurementUnit, string amount, string price);
    string getBarCode() { return this->_barCode; };
    string getDescription() { return this->_description; };
    SellAmount *getSellAmount() { return this->_sellAmount; };
    string getMeasurementUnit() { return this->_measurementUnit; };
    float getAmount() { return this->_amount; };
    float getUnitPrice() { return this->_unitPrice; };
    string toString();
};

#endif
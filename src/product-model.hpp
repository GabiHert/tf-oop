#ifndef ProductModel_h
#define ProductModel_h
// #pragma once

#include "product-dto.hpp"
#include <string>

using namespace std;

class ProductModel
{
private:
    string _barCode;
    string _description;
    SellAmount *_sellAmount;
    string _measurementUnit;
    float _amount;
    int _unitPrice;

public:
    ProductModel(ProductDto *productDto);
    string getBarCode() { return this->_barCode; };
    string getDescription() { return this->_description; };
    SellAmount *getSellAmount() { return this->_sellAmount; };
    string getMeasurementUnit() { return this->_measurementUnit; };
    float getAmount() { return this->_amount; };
    int getUnitPrice() { return this->_unitPrice; };
    string toString();
};

#endif

#ifndef BuyRegister_h
#define BuyRegister_h
// #pragma once

#include "discount-model.hpp"
#include "product-model.hpp"
#include "sell-amount.hpp"
class BuyRegister
{
private:
    string _barCode;
    string _description;
    float _unitPrice;
    string _measurementUnit;
    float _units;
    float _discount;
    float _price;
    SellAmount *_sellAmount;

public:
    BuyRegister(ProductModel *productModel, float units);
    string getBarCode() { return this->_barCode; };
    string getDescription() { return this->_description; };
    float getUnitPrice() { return this->_unitPrice; };
    string getMeasurementUnit() { return this->_measurementUnit; };
    void addUnits(float units);
    float getUnits();
    SellAmount *getSellAmount() { return this->_sellAmount; };
    float getDiscount()
    {
        return this->_discount;
    }
    float getPrice()
    {
        return this->_price;
    };
    void addDiscount(float discount);
    string toString();
};

#endif

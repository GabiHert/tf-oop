#ifndef SimpleDiscount_h
#define SimpleDiscount_h
// #pragma once

#include "discount-model.hpp"
#include "./discount.hpp"
class SimpleDiscount : public Discount
{
private:
    string _barCode;
    float _discount;

public:
    SimpleDiscount(DiscountModel *discountModel);
    void apply(vector<BuyRegister *> *buyRegisters);
    string getBarCode() { return _barCode; }
    float getDiscount() { return _discount; }
    string toString();
};

#endif
#ifndef TakeMPayNDiscount_h
#define TakeMPayNDiscount_h
// #pragma once

#include "discount-model.hpp"
#include "./discount.hpp"
#include "buy-register.hpp"
#include <vector>
class TakeMPayNDiscount : public Discount
{
private:
    string _barCode;
    int _amountToBeTook;
    int _amountToBePaid;

public:
    TakeMPayNDiscount(DiscountModel *discountModel);
    void apply(vector<BuyRegister *> *buyRegisters);
    string getBarCode() { return _barCode; }
    int getAmountToBeTook() { return _amountToBeTook; }
    int getAmountToBePaid() { return _amountToBePaid; }
    string toString();
};

#endif
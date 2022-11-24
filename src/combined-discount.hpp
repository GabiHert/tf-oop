#ifndef CombinedDiscount_h
#define CombinedDiscount_h
// #pragma once

#include "discount-model.hpp"
#include "discount.hpp"
#include "product-model.hpp"
#include "buy-register.hpp"
#include <vector>

class CombinedDiscount : public Discount
{
private:
    string _barCodeA;
    int _amountToBeTook;
    int _amountToBeApplied;
    string _barCodeB;
    float _discountPercentage;

public:
    CombinedDiscount(DiscountModel *discountModel);
    void apply(vector<BuyRegister *> *buyRegisters);
    string getBarCodeA() { return _barCodeA; }
    int getAmountToBeTook() { return _amountToBeTook; }
    int getAmountToBeApplied() { return _amountToBeApplied; }
    string getBarCodeB() { return _barCodeB; }
    float getDiscountPercentage() { return _discountPercentage; }
    string toString();
};

#endif
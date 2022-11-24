#ifndef discountFactory_h
#define discountFactory_h
//#pragma once

#include "discount.hpp"
#include "combined-discount.hpp"
#include "simple-discount.hpp"
#include "take-m-pay-n-discount.hpp"
#include "discount-model.hpp"
#include "buy-register.hpp"

class DiscountFactory
{
private:
public:
    static Discount *GetInstance(DiscountModel *discountModel, vector<BuyRegister *> *buyRegisters);
};

#endif
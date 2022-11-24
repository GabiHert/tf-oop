#ifndef ApplyDiscountUseCase_h
#define ApplyDiscountUseCase_h
// #pragma once

#include "buy-register.hpp"
#include <vector>

class ApplyDiscountUseCase
{
private:
public:
    static void Execute(vector<BuyRegister *> *buyRegisters, vector<DiscountModel *> *discountModel);
};

#endif
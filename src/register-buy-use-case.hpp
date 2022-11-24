#ifndef RegisterBuyUseCase_h
#define RegisterBuyUseCase_h
// #pragma once

#include "buy-register.hpp"
#include "buy-request-model.hpp"
#include "product-model.hpp"
#include <vector>

class RegisterBuyUseCase
{
private:
public:
    static void Execute(vector<BuyRegister *> *buyRegisters, BuyRequestModel *buyRequestsModel, vector<ProductModel *> *productsModel);
};

#endif
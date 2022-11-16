#ifndef RegisterBuyUseCase_h
#define RegisterBuyUseCase_h

#include "../domain/invoice/buy-register.hpp"
#include "../domain/model/buy-request-model.hpp"
#include "../domain/model/product-model.hpp"
#include <vector>

class RegisterBuyUseCase
{
private:
    RegisterBuyUseCase();

public:
    static void Execute(BuyRegister *buyRegister, BuyRequestModel *buyRequestsModel, vector<ProductModel *> productsModel);
};

#endif
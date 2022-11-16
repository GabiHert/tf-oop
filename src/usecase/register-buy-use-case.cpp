#include "./register-buy-use-case.hpp"

void RegisterBuyUseCase::Execute(BuyRegister *buyRegister, BuyRequestModel *buyRequestsModel, vector<ProductModel *> productsModel)
{
    int index = 0;
    while (buyRequestsModel->getBarCode() != productsModel.at(index)->getBarCode())
        index++;

    buyRegister = new BuyRegister(productsModel.at(index));
}

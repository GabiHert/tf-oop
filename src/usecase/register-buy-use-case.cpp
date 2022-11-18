#include "./register-buy-use-case.hpp"
#include <iostream>
using namespace std;

void RegisterBuyUseCase::Execute(vector<BuyRegister *> buyRegisters, BuyRequestModel *buyRequestsModel, vector<ProductModel *> productsModel)
{
    cout << "RegisterBuyUseCase::Execute - Process started" << endl;
    int index = 0;
    while (buyRequestsModel->getBarCode() != productsModel.at(index)->getBarCode())
        index++;

    bool isNewRegister = true;
    for (int i = 0; i < int(buyRegisters.size()); i++)
    {
        if (buyRegisters[i]->getBarCode() == productsModel[index]->getBarCode())
        {
            isNewRegister = false;
            buyRegisters[i]->addUnit();
        }
    }

    if (isNewRegister)
        buyRegisters.push_back(new BuyRegister(productsModel[index]));
    cout << "RegisterBuyUseCase::Execute - Process finished" << endl;
}

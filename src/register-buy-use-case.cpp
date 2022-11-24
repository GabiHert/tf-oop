#include "./register-buy-use-case.hpp"
#include <iostream>
#include "utils.hpp"
using namespace std;

void RegisterBuyUseCase::Execute(vector<BuyRegister *> *buyRegisters, BuyRequestModel *buyRequestModel, vector<ProductModel *> *productsModel)
{
    cout << "RegisterBuyUseCase::Execute - Process started" << endl;
    int index = 0;
    while (index < int(productsModel->size()) && buyRequestModel->getBarCode() != productsModel->at(index)->getBarCode())
        index++;

    if (index > int(productsModel->size()))
    {
        throw "PRODUCT " + buyRequestModel->getBarCode() + "NOT FOUND!";
    }

    bool isNewRegister = true;
    for (int i = 0; i < int(buyRegisters->size()); i++)
    {
        if (buyRegisters->at(i)->getBarCode() == productsModel->at(index)->getBarCode())
        {
            isNewRegister = false;
            buyRegisters->at(i)->addUnits(buyRequestModel->getAmount());
            cout << "RegisterBuyUseCase::Execute - Added unit to old register: " << buyRegisters->at(i)->toString() << endl;
        }
    }

    if (isNewRegister)
    {
        if (buyRequestModel->getAmount())
        {
            BuyRegister *buyRegister = new BuyRegister(productsModel->at(index), buyRequestModel->getAmount());
            buyRegisters->push_back(buyRegister);
            cout << "RegisterBuyUseCase::Execute - Added new register: " << buyRegister->toString() << endl;
        }
        else
        {
            cout << "RegisterBuyUseCase::Execute - Register ignored - Product " << productsModel->at(index)->toString() << endl;
        }
    }

    cout << "RegisterBuyUseCase::Execute - Process finished" << endl;
}

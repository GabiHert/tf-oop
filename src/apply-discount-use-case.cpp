

#include "apply-discount-use-case.hpp"
#include "discount.hpp"
#include "discount-factory.hpp"
#include <iostream>
using namespace std;

void ApplyDiscountUseCase::Execute(vector<BuyRegister *> *buyRegisters, vector<DiscountModel *> *discountsModel)
{
    cout << "ApplyDiscountUseCase::Execute - Process started - DiscountModel size: " << discountsModel->size() << endl;

    Discount *discount;

    for (int i = 0; i < int(discountsModel->size()); i++)
    {

        discount = DiscountFactory::GetInstance(discountsModel->at(i), buyRegisters);
        discount->apply(buyRegisters);
    }

    cout << "ApplyDiscountUseCase::Execute - Process finished" << endl;
}

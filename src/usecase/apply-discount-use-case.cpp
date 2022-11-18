

#include "./apply-discount-use-case.hpp"
#include "../domain/discount/discount.hpp"
#include "../domain/factory/discount-factory.hpp"
#include <iostream>
using namespace std;

void ApplyDiscountUseCase::Execute(vector<BuyRegister *> buyRegisters, int index, vector<DiscountModel *> discountsModel)
{
    cout << "ApplyDiscountUseCase::Execute - Process started" << endl;

    Discount *discount;

    for (int i = 0; i < int(discountsModel.size()); i++)
    {
        discount = DiscountFactory::GetInstance(discountsModel[i], buyRegisters);

        if (discount->getBarCode() == buyRegisters[index]->getBarCode())
        {
            buyRegisters[index]->addDiscount(discount->getDiscountValue());
        }
    }

    cout << "ApplyDiscountUseCase::Execute - Process finished" << endl;
}

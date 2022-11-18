

#include "./apply-discount-use-case.hpp"
#include "../domain/discount/discount.hpp"
#include "../domain/factory/discount-factory.hpp"

void ApplyDiscountUseCase::Execute(vector<BuyRegister *> buyRegisters, int index, vector<DiscountModel *> discountsModel)
{
    Discount *discount;

    for (int i = 0; i < discountsModel.size(); i++)
    {
        discount = DiscountFactory::GetInstance(discountsModel[i], buyRegisters);

        if (discount->getBarCode() == buyRegisters[index]->getBarCode())
        {
            buyRegisters[index]->addDiscount(discount->getDiscountValue());
        }
    }
}



#include "./apply-discount-use-case.hpp"
#include "../domain/discount/discount.hpp"
#include "../domain/factory/discount-factory.hpp"

void ApplyDiscountUseCase::Execute(BuyRegister *buyRegister, vector<DiscountModel *> discountsModel)
{
    Discount discount;

    for (int i = 0; i < discountsModel.size(); i++)
    {
        discount = DiscountFactory::GetInstance(discountsModel[i]);

        if (discount.getBarCode() == buyRegister->getBarCode())
        {
            buyRegister->addDiscount(discount.getDiscountValue());
        }
    }
}

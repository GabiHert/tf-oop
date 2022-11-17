#include "./discount-factory.hpp"
#include "../discount/combined-discount.hpp"
#include "../discount/simple-discount.hpp"
#include "../discount/take-m-pay-n-discount.hpp"

Discount *DiscountFactory::GetInstance(DiscountModel *discountModel)
{
    if (discountModel->getField2())
        return new SimpleDiscount(discountModel);
    if (discountModel->getField5().length() > 0)
        return new CombinedDiscount(discountModel);
    else
        return new TakeMPayNDiscount(discountModel);
}

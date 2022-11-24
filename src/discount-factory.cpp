#include "./discount-factory.hpp"
#include "combined-discount.hpp"
#include "simple-discount.hpp"
#include "take-m-pay-n-discount.hpp"
#include <iostream>
using namespace std;

Discount *DiscountFactory::GetInstance(DiscountModel *discountModel, vector<BuyRegister *> *buyRegisters)
{
    cout << "DiscountFactory::GetInstance - Process started - " << discountModel->toString() << endl;

    Discount *discount;
    if (discountModel->getField2())
        discount = new SimpleDiscount(discountModel);
    else if (discountModel->getField5().length() > 0)
        discount = new CombinedDiscount(discountModel);
    else
        discount = new TakeMPayNDiscount(discountModel);
    cout << "DiscountFactory::GetInstance - Process finished" << endl;
    return discount;
}

#include "./discount-factory.hpp"
#include "../discount/combined-discount.hpp"
#include "../discount/simple-discount.hpp"
#include "../discount/take-m-pay-n-discount.hpp"
#include <iostream>
using namespace std;

Discount *DiscountFactory::GetInstance(DiscountModel *discountModel, vector<BuyRegister *> buyRegisters)
{
    cout << "DiscountFactory::GetInstance - Process started" << endl;
    Discount *discount;
    if (discountModel->getField2())
        discount = new SimpleDiscount(discountModel);
    if (discountModel->getField5().length() > 0)
        discount = new CombinedDiscount(discountModel, buyRegisters);
    else
        discount = new TakeMPayNDiscount(discountModel, buyRegisters);

    cout << "DiscountFactory::GetInstance - Process finished" << endl;
    return discount;
}

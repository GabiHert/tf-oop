#ifndef discountFactory_h
#define discountFactory_h

#include "../discount/discount.hpp"
#include "../discount/combined-discount.hpp"
#include "../discount/simple-discount.hpp"
#include "../discount/take-m-pay-n-discount.hpp"
#include "../model/discount-model.hpp"
#include "../invoice/buy-register.hpp"

class DiscountFactory
{
private:
    DiscountFactory();

public:
    static Discount *GetInstance(DiscountModel *discountModel, vector<BuyRegister *> buyRegisters);
};

#endif
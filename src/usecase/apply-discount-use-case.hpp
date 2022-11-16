#ifndef ApplyDiscountUseCase_h
#define ApplyDiscountUseCase_h

#include "../domain/invoice/buy-register.hpp"
#include <vector>

class ApplyDiscountUseCase
{
private:
    ApplyDiscountUseCase();

public:
    static void Execute(BuyRegister *buyRegister, vector<DiscountModel *> discountModel);
};

#endif
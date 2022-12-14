#ifndef ApplyDiscountUseCase_h
#define ApplyDiscountUseCase_h

#include "../domain/invoice/buy-register.hpp"
#include <vector>

class ApplyDiscountUseCase
{
private:
public:
    ApplyDiscountUseCase(){};
    static void Execute(vector<BuyRegister *> buyRegisters, int index, vector<DiscountModel *> discountModel);
};

#endif
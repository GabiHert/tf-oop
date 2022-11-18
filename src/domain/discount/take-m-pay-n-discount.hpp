#ifndef TakeMPayNDiscount_h
#define TakeMPayNDiscount_h
#include "../model/discount-model.hpp"
#include "./discount.hpp"
#include "../invoice/buy-register.hpp"
#include <vector>
class TakeMPayNDiscount : public Discount
{
private:
    string _barCode;
    int _amountToBeTook;
    int _amountToBePaid;

public:
    TakeMPayNDiscount(DiscountModel *discountModel, vector<BuyRegister *> buyRegisters);
    string getBarCode() const { return _barCode; }
    int getAmountToBeTook() const { return _amountToBeTook; }
    int getAmountToBePaid() const { return _amountToBePaid; }
};

#endif
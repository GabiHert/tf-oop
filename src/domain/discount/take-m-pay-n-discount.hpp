#ifndef TakeMPayNDiscount_h
#define TakeMPayNDiscount_h
#include "../model/discount-model.hpp"
#include "./discount.hpp"
class TakeMPayNDiscount : public Discount
{
private:
    string _barCode;
    int _amountTobeTook;
    int _amountToBePaid;

public:
    TakeMPayNDiscount(DiscountModel discountModel);
    string getBarCode() const { return _barCode; }
    int getAmountTobeTook() const { return _amountTobeTook; }
    int getAmountToBePaid() const { return _amountToBePaid; }
};

#endif
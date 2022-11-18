#ifndef SimpleDiscount_h
#define SimpleDiscount_h

#include "../model/discount-model.hpp"
#include "./discount.hpp"
class SimpleDiscount : public Discount
{
private:
    string _barCode;
    float _discount;

public:
    SimpleDiscount(DiscountModel *discountModel);
    string getBarCode() { return _barCode; }
    float getDiscount() { return _discount; }
};

#endif
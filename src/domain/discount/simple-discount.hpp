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
    SimpleDiscount(DiscountModel discountModel);
    string getBarCode() const { return _barCode; }
    float getDiscount() const { return _discount; }
};

#endif
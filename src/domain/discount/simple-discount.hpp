#ifndef SimpleDiscount_h
#define SimpleDiscount_h

#include "domain/model/discount-model.hpp"
class SimpleDiscount
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
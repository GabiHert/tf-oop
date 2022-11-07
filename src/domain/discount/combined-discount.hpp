#ifndef CombinedDiscount_h
#define CombinedDiscount_h
#include "domain/model/discount-model.hpp"

class CombinedDiscount
{
private:
    string _barCodeA;
    int _amountToBeTook;
    int _amountToBeApplied;
    string _barCodeB;
    int _discountPercentage;

public:
    CombinedDiscount(DiscountModel discountModel);
    string getBarCodeA() const { return _barCodeA; }
    int getAmountToBeTook() const { return _amountToBeTook; }
    int _amountToBeApplied() const { return _amountToBeApplied; }
    string getBarCodeB() const { return _barCodeB; }
    int getDiscountPercentage() const { return _discountPercentage; }
};

#endif
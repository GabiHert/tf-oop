#ifndef CombinedDiscount_h
#define CombinedDiscount_h
#include "../model/discount-model.hpp"
#include "./discount.hpp"
#include "../model/product-model.hpp"
#include "../invoice/buy-register.hpp"
#include <vector>

class CombinedDiscount : public Discount
{
private:
    string _barCodeA;
    int _amountToBeTook;
    int _amountToBeApplied;
    string _barCodeB;
    int _discountPercentage;

public:
    CombinedDiscount(DiscountModel *discountModel, vector<BuyRegister *> buyRegisters);
    string getBarCodeA() const { return _barCodeA; }
    int getAmountToBeTook() const { return _amountToBeTook; }
    int getAmountToBeApplied() const { return _amountToBeApplied; }
    string getBarCodeB() const { return _barCodeB; }
    int getDiscountPercentage() const { return _discountPercentage; }
};

#endif
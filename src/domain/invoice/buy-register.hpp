
#ifndef BuyRegister_h
#define BuyRegister_h

#include "../../domain/model/discount-model.hpp"
#include "../../domain/model/product-model.hpp"
class BuyRegister
{
private:
    string _barCode;
    string _description;
    float _unitPrice;
    string _measurementUnit;
    float _amount;
    float _discount;
    float _price;

public:
    BuyRegister();
    BuyRegister(ProductModel *productModel);
    string getBarCode();
    string getDescription();
    float getUnitPrice();
    string getMeasurementUnit();
    float getAmount();
    float getDiscount();
    float getPrice();

    void addDiscount(float discount);
};

#endif


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
    BuyRegister(){};
    BuyRegister(ProductModel *productModel);
    string getBarCode() { return this->_barCode; };
    string getDescription() { return this->_description; };
    float getUnitPrice() { return this->_unitPrice; };
    string getMeasurementUnit() { return this->_measurementUnit; };
    float getAmount() { return this->_amount; };
    void addUnit();
    void removeUnit();
    float getDiscount() { return this->_discount; }
    float getPrice() { return this->_price; };
    void addDiscount(float discount);
};

#endif

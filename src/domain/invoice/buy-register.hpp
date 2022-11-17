
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
    string getBarCode() const { return this->_barCode; };
    string getDescription() const { return this->_description; };
    float getUnitPrice() const { return this->_unitPrice; };
    string getMeasurementUnit() const { return this->_measurementUnit; };
    float getAmount() const { return this->_amount; };
    float getDiscount() const { return this->_discount; }
    float getPrice() const { return this->_price; };

    void addDiscount(float discount);
};

#endif

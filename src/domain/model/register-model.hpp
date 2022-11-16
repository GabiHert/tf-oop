
#ifndef RegisterModel_h
#define RegisterModel_h
#include "./product-model.hpp"
#include "./discount-model.hpp"
class RegisterModel
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
    RegisterModel(ProductModel *productModel, DiscountModel *discountModel);
    string getBarCode();
    string getDescription();
    float getUnitPrice();
    string getMeasurementUnit();
    float getAmount();
    float getDiscount();
    float getPrice();
};

#endif // RegisterModel

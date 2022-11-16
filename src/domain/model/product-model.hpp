#ifndef ProductModel_h
#define ProductModel_h
#include "../../domain/dto/product-dto.hpp"
#include <string>
using namespace std;

class ProductModel
{
private:
    string _barCode;
    string _description;
    string _sellAmount; // todo:unit or bulk
    string _measurementUnit;
    int _amount;
    int _unitPrice;

public:
    ProductModel(ProductDto *productDto);
    string getBarCode() const { return this->_barCode; };
    string getDescription() const { return this->_description; };
    string getSellAmount() const { return this->_sellAmount; };
    string getMeasurementUnit() const { return this->_measurementUnit; };
    int getAmount() const { return this->_amount; };
    int getUnitPrice() const { return this->_unitPrice; };
};

#endif
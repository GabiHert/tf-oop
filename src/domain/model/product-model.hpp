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
    string getBarCode() { return this->_barCode; };
    string getDescription() { return this->_description; };
    string getSellAmount() { return this->_sellAmount; };
    string getMeasurementUnit() { return this->_measurementUnit; };
    int getAmount() { return this->_amount; };
    int getUnitPrice() { return this->_unitPrice; };
};

#endif
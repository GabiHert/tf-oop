#ifndef ProductDto_h
#define ProductDto_h
#include <string>
#include <vector>
using namespace std;

class ProductDto
{
private:
    string _barCode;
    string _description;
    string _sellAmount; // todo:unit or bulk
    string _measurementUnit;
    int _amount;
    int _unitPrice;

public:
    ProductDto(string barCode, string description, string sellAmount, string measurementUnit, string amount, string price);
    string getBarCode() { return this->_barCode; };
    string getDescription() { return this->_description; };
    string getSellAmount() { return this->_sellAmount; };
    string getMeasurementUnit() { return this->_measurementUnit; };
    int getAmount() { return this->_amount; };
    int getUnitPrice() { return this->_unitPrice; };
};

#endif
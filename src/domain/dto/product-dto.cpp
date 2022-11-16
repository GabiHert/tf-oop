

#include "./product-dto.hpp"
ProductDto::ProductDto(string barCode, string description, string sellAmount, string measurementUnit, string amount, string unitPrice)
{
    this->_barCode = barCode;
    this->_description = description;
    this->_sellAmount = sellAmount;
    this->_measurementUnit = measurementUnit;
    this->_amount = stof(amount);
    this->_unitPrice = stof(unitPrice);
}

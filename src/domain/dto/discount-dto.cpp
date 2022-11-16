

#include "./discount-dto.hpp"

DiscountDto::DiscountDto(string field1, string field2, string field3, string field4, string field5, string field6)
{
    this->_field1 = field1;
    this->_field2 = stof(field2);
    this->_field3 = stof(field3);
    this->_field4 = stof(field4);
    this->_field5 = field5;
    this->_field6 = stof(field6);
}

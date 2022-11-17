#include "./discount-model.hpp"
DiscountModel::DiscountModel(DiscountDto *discountDto)
{
    this->_field1 = discountDto->getField1();
    this->_field2 = discountDto->getField2();
    this->_field3 = discountDto->getField3();
    this->_field4 = discountDto->getField4();
    this->_field5 = discountDto->getField5();
    this->_field6 = discountDto->getField6();
}

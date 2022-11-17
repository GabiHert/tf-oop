#include "./simple-discount.hpp"

SimpleDiscount::SimpleDiscount(DiscountModel *discountModel)
{
    this->_barCode = discountModel->getField1();
    this->_discount = discountModel->getField2();
}
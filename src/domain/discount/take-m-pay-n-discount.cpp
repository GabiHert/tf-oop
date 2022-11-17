#include "./take-m-pay-n-discount.hpp"

TakeMPayNDiscount::TakeMPayNDiscount(DiscountModel *discountModel)
{
    this->_barCode = discountModel->getField1();
    this->_amountToBeTook = discountModel->getField3();
    this->_amountToBePaid = discountModel->getField4();
}
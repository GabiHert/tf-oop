#include "./combined-discount.hpp"

CombinedDiscount::CombinedDiscount(DiscountModel *discountModel)
{
    this->_barCodeA = discountModel->getField1();
    this->_amountToBeTook = discountModel->getField3();
    this->_amountToBeApplied = discountModel->getField4();
    this->_barCodeB = discountModel->getField5();
    this->_discountPercentage = discountModel->getField6();
}
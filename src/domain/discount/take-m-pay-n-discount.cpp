#include "./take-m-pay-n-discount.hpp"

TakeMPayNDiscount::TakeMPayNDiscount(DiscountModel *discountModel, vector<BuyRegister *> buyRegisters)
{
    this->_barCode = discountModel->getField1();
    this->_amountToBeTook = discountModel->getField3();
    this->_amountToBePaid = discountModel->getField4();

    int i = 0;
    while (buyRegisters[i]->getBarCode() != this->_barCode)
    {
        /* code */
    }
}
#include "./combined-discount.hpp"

CombinedDiscount::CombinedDiscount(DiscountModel *discountModel, vector<BuyRegister *> buyRegisters)
{
    this->_barCodeA = discountModel->getField1();
    this->_amountToBeTook = discountModel->getField3();
    this->_amountToBeApplied = discountModel->getField4();
    this->_barCodeB = discountModel->getField5();
    this->_discountPercentage = discountModel->getField6();

    // se levar _amountToBeTook do _barCodeA, dai _amountToBeApplied dos produtos do _BarCodeB tera _discountPercentage de desconto
    BuyRegister *productABuyRegister, *productBBuyRegister;
    for (int i = 0; i < buyRegisters.size(); i++)
    {
        if (buyRegisters[i]->getBarCode() == this->_barCodeA)
            productABuyRegister = buyRegisters[i];

        if (buyRegisters[i]->getBarCode() == this->_barCodeB)
            productBBuyRegister = buyRegisters[i];
    }

    if (productABuyRegister->getAmount() >= this->_amountToBeTook)
    {
        for (int i = 0; (i < productBBuyRegister->getAmount()) && (i < this->getAmountToBeApplied()); i++)
        {
            this->setDiscountValue(this->getDiscountValue() + (this->_discountPercentage * productABuyRegister->getUnitPrice()));
        }
    }
}
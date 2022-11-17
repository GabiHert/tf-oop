#include "./buy-register.hpp"

BuyRegister::BuyRegister()
{
}
BuyRegister::BuyRegister(ProductModel *productModel)
{
    this->_amount = productModel->getAmount();
    this->_barCode = productModel->getBarCode();
    this->_description = productModel->getDescription();
    this->_measurementUnit = productModel->getMeasurementUnit();
    this->_unitPrice = productModel->getUnitPrice();
}
void BuyRegister::addDiscount(float discount)
{
    this->_discount = discount > 0 ? this->_discount - discount : this->_discount + discount;
}

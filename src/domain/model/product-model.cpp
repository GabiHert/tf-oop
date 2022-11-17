#include "./product-model.hpp"
ProductModel::ProductModel(ProductDto *productDto)
{
    this->_amount = productDto->getAmount();
    this->_barCode = productDto->getBarCode();
    this->_description = productDto->getDescription();
    this->_measurementUnit = productDto->getMeasurementUnit();
    this->_sellAmount = productDto->getSellAmount();
    this->_unitPrice = productDto->getUnitPrice();
}
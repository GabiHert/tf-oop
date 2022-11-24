#include "./product-model.hpp"
#include <sstream>
#include <iostream>
using namespace std;

ProductModel::ProductModel(ProductDto *productDto)
{
    this->_amount = productDto->getAmount();
    this->_barCode = productDto->getBarCode();
    this->_description = productDto->getDescription();
    this->_measurementUnit = productDto->getMeasurementUnit();
    this->_sellAmount = productDto->getSellAmount();
    this->_unitPrice = productDto->getUnitPrice();

    cout << "ProductModel::ProductModel - " << this->toString() << endl;
}

string ProductModel::toString()
{

    stringstream stream;

    stream << "ProductModel: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _amount: " << this->_amount << endl;
    stream << " _description: " << this->_description << endl;
    stream << " _measurementUnit: " << this->_measurementUnit << endl;
    stream << " _sellAmount: " << this->_sellAmount->getName() << endl;
    stream << " _unitPrice: " << this->_unitPrice << endl;

    return stream.str();
}
#include "./discount-model.hpp"
#include <iostream>
using namespace std;
#include <sstream>

DiscountModel::DiscountModel(DiscountDto *discountDto)
{
    cout << "DiscountModel::DiscountModel - Process started" << endl;

    this->_field1 = discountDto->getField1();
    this->_field2 = discountDto->getField2();
    this->_field3 = discountDto->getField3();
    this->_field4 = discountDto->getField4();
    this->_field5 = discountDto->getField5();
    this->_field6 = discountDto->getField6();
    cout << "DiscountModel::DiscountModel - Process finished " << this->toString() << endl;
}

string DiscountModel::toString()
{

    stringstream stream;

    stream << "DiscountModel: " << endl;
    stream << "_field1: " << this->_field1 << endl;
    stream << "_field2: " << this->_field2 << endl;
    stream << "_field3: " << this->_field3 << endl;
    stream << "_field4: " << this->_field4 << endl;
    stream << "_field5: " << this->_field5 << endl;
    stream << "_field6: " << this->_field6 << endl;

    return stream.str();
}

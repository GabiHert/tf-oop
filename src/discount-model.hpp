#ifndef DiscountModel_h
#define DiscountModel_h
//#pragma once

#include <string>
#include "discount-dto.hpp"
using namespace std;

class DiscountModel
{
private:
    string _field1;
    float _field2;
    int _field3;
    int _field4;
    string _field5;
    float _field6;

public:
    DiscountModel(DiscountDto *discountDto);
    string getField1() { return this->_field1; }
    float getField2() { return this->_field2; }
    int getField3() { return this->_field3; }
    int getField4() { return this->_field4; }
    string getField5() { return this->_field5; }
    float getField6() { return this->_field6; }
    string toString();
};

#endif
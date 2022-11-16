#ifndef DiscountModel_h
#define DiscountModel_h
#include <string>
#include "../../domain/dto/discount-dto.hpp"
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
    string getField1() const { return this->_field1; }
    float getField2() const { return this->_field2; }
    int getField3() const { return this->_field3; }
    int getField4() const { return this->_field4; }
    string getField5() const { return this->_field5; }
    float getField6() const { return this->_field6; }
};

#endif
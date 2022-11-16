#ifndef DiscountDto_h
#define DiscountDto_h
#include <string>
#include <vector>
using namespace std;

class DiscountDto
{
private:
    string _field1;
    float _field2;
    int _field3;
    int _field4;
    string _field5;
    float _field6;

public:
    DiscountDto(string field1, string field2, string field3, string field4, string field5, string field6);
    string getField1() const { return this->_field1; }
    float getField2() const { return this->_field2; }
    int getField3() const { return this->_field3; }
    int getField4() const { return this->_field4; }
    string getField5() const { return this->_field5; }
    float getField6() const { return this->_field6; }
};

#endif
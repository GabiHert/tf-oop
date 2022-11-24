

#include "./discount-dto.hpp"
#include <sstream>
#include <iostream>
using namespace std;

DiscountDto::DiscountDto(string field1, string field2, string field3, string field4, string field5, string field6)
{
    cout << "DiscountDto::DiscountDto - Process started" << endl;

    this->_field1 = field1;

    if (field2.length())
        this->_field2 = stof(field2);
    else
        this->_field2 = 0;

    if (field3.length())
        this->_field3 = stof(field3);
    else
        this->_field3 = 0;

    if (field4.length())
        this->_field4 = stof(field4);
    else
        this->_field4 = 0;

    this->_field5 = field5;

    if (field6.length())
        this->_field6 = stof(field6);
    else
        this->_field6 = 0;

    cout << "DiscountDto::DiscountDto - Process finished " << this->toString() << endl;
}
string DiscountDto::toString()
{

    stringstream stream;

    stream << "DiscountDto: " << endl;
    stream << " _field1: " << this->_field1 << endl;
    stream << " _field2: " << this->_field2 << endl;
    stream << " _field3: " << this->_field3 << endl;
    stream << " _field4: " << this->_field4 << endl;
    stream << " _field5: " << this->_field5 << endl;
    stream << " _field6: " << this->_field6 << endl;

    return stream.str();
}
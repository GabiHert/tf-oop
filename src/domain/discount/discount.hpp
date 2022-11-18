#ifndef discount_h
#define discount_h
#include <string>
using namespace std;

class Discount
{
private:
    float _discountValue;
    string _barCode;

protected:
    void setDiscountValue(float value)
    {
        this->_discountValue = value;
    };
    void setBarCode(string barCode)
    {
        this->_barCode = barCode;
    };

public:
    Discount(){};
    float getDiscountValue()
    {
        return this->_discountValue;
    };
    string getBarCode()
    {
        return this->_barCode;
    }
};

#endif
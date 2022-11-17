#include <string>
#include <vector>
using namespace std;

#ifndef buy_request_dto_h
#define buy_request_dto_h

class BuyRequestDto
{
private:
    string _barCode;
    float _amount;

public:
    BuyRequestDto();
    BuyRequestDto(string barCode, string amount);
    string getBarCode() const { return _barCode; }
    float getAmount() const { return _amount; }
};

#endif
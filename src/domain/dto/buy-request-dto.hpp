#include <string>
#include <vector>
using namespace std;

#ifndef buy_request_dto_h
#define buy_request_dto_h

class BuyRequestDto
{
private:
    string _barCode;
    string _amount;

public:
    BuyRequestDto();
    BuyRequestDto(string barCode, string amount);
    string getBarCode() const { return _barCode; }
    string getAmount() const { return _amount; }
};

#endif
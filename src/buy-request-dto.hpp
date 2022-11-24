
#ifndef buy_request_dto_h
#define buy_request_dto_h
//#pragma once

#include <string>
#include <vector>
using namespace std;
class BuyRequestDto
{
private:
    string _barCode;
    float _amount;

public:
    BuyRequestDto(string barCode, string amount);
    string getBarCode() { return _barCode; }
    float getAmount() { return _amount; }
    string toString();
};

#endif
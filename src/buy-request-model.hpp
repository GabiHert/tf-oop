#ifndef buy_request_model_h
#define buy_request_model_h
//#pragma once

#include <string>
#include <vector>
#include "buy-request-dto.hpp"
using namespace std;
class BuyRequestModel
{
private:
    string _barCode;
    float _amount;

public:
    BuyRequestModel(BuyRequestDto *buyRequestDto);
    string getBarCode() { return _barCode; }
    float getAmount() { return _amount; }
    string toString();
};
#endif
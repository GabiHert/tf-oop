#include <string>
#include <vector>
#include "../../domain/dto/buy-request-dto.hpp"
using namespace std;

#ifndef buy_request_model_h
#define buy_request_model_h

class BuyRequestModel
{
private:
    string _barCode;
    float _amount;

public:
    BuyRequestModel(BuyRequestDto *buyRequestDto);
    string getBarCode() { return _barCode; }
    float getAmount() { return _amount; }
};

#endif
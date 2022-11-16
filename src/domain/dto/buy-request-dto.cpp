#include "./buy-request-dto.hpp"
BuyRequestDto::BuyRequestDto(string barCode, string amount)
{
    this->_barCode = barCode;
    this->_amount = amount;
}

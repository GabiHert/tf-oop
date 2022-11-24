#include "./buy-request-dto.hpp"
#include <sstream>
BuyRequestDto::BuyRequestDto(string barCode, string amount)
{
    this->_barCode = barCode;
    this->_amount = stof(amount);
}

string BuyRequestDto::toString()
{

    stringstream stream;

    stream << "BuyRequestDto: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _amount: " << this->_amount << endl;

    return stream.str();
}

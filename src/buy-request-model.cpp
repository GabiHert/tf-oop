
#include "./buy-request-dto.hpp"
#include "./buy-request-model.hpp"
#include <sstream>
#include <iostream>
using namespace std;

BuyRequestModel::BuyRequestModel(BuyRequestDto *buyRequestDto)
{
    cout << "BuyRequestModel::BuyRequestModel - Process started" << endl;

    this->_barCode = buyRequestDto->getBarCode();
    this->_amount = buyRequestDto->getAmount();

    cout << "BuyRequestModel::BuyRequestModel - Process finished - " << this->toString() << endl;
}

string BuyRequestModel::toString()
{

    stringstream stream;

    stream << "BuyRequestModel: " << endl;
    stream << " _barCode: " << this->_barCode << endl;
    stream << " _amount: " << this->_amount << endl;

    return stream.str();
}

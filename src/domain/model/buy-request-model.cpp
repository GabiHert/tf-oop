
#include "./buy-request-dto.hpp"
#include "./buy-request-model.hpp"
BuyRequestModel::BuyRequestModel(BuyRequestDto *buyRequestDto)
{
    this->_barCode = buyRequestDto->getBarCode();
    this->_amount = buyRequestDto->getAmount();
}

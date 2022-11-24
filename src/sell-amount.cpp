#include "sell-amount.hpp"

string SellAmount::Unit = "unidade";
string SellAmount::Bulk = "granel";

SellAmount::SellAmount(string name)
{
    if (name != this->Bulk && name != this->Unit)
        throw "Unknown sell amount";
    this->name = name;
};
#ifndef discount_h
#define discount_h
// #pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "buy-register.hpp"
using namespace std;

class Discount
{

public:
    virtual string toString()
    {
        throw "DISCOUNT::toString not implemented";
    };

    virtual void apply(vector<BuyRegister *> *buyRegisters)
    {
        throw "DISCOUNT::apply not implemented";
    };
};

#endif
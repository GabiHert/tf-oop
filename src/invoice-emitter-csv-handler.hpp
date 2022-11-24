#ifndef InvoiceEmitter_h
#define InvoiceEmitter_h
//#pragma once

#include <string>
using namespace std;

class InvoiceEmitterCsv
{
private:
public:
    static void Execute(string buyRequestsDataFilePath, string companyDataFilePath, string productDataFilePath, string discountDataFilePath);
};

#endif

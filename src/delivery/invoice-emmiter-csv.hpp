#ifndef InvoiceEmitter_h
#define InvoiceEmitter_h
#include <string>
using namespace std;

class InvoiceEmitterCsv
{
public:
    static void Execute(string companyDataFilePath, string productDataFilePath, string discountDataFilePath);
};

#endif

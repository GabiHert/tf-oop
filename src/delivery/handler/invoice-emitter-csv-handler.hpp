#ifndef InvoiceEmitter_h
#define InvoiceEmitter_h
#include <string>
using namespace std;

class InvoiceEmitterCsv
{
private:
public:
    InvoiceEmitterCsv(){};

    void execute(string buyRequestsDataFilePath, string companyDataFilePath, string productDataFilePath, string discountDataFilePath);
};

#endif


#include "delivery/handler/invoice-emitter-csv-handler.hpp"
#include <string>
using namespace std;
int main()
{

    InvoiceEmitterCsv invoiceEmitterCsv = InvoiceEmitterCsv();
    string t = " ";
    invoiceEmitterCsv.execute(t, t, t, t);
};

#include "invoice-emitter-csv-handler.hpp"
#include <cstdio>
#include <iostream>
int main()
{
    freopen("debug.txt", "w", stdout);
    InvoiceEmitterCsv::Execute("data/compras.csv", "data/empresa.csv", "data/produtos.csv", "data/desconto.csv");
    return 0;
}
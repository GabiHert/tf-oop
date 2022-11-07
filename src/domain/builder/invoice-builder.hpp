#ifndef InvoiceBuilder
#define InvoiceBuilder
#include <string>
#include "domain/model/product-model.hpp"
using namespace std;

class InvoiceBuilder
{
private:
    InvoiceBuilder();

public:
    static string Build(ProductModel *ProductModel);
}

#endif
#ifndef Invoice_emitter_h
#define Invoice_emitter_h

#include "../domain/dto/company-dto.hpp"
#include "../domain/dto/product-dto.hpp"
#include "../domain/dto/buy-request-dto.hpp"
#include "../domain/dto/discount-dto.hpp"
#include "../domain/invoice/invoice.hpp"
#include "../domain/model/company-model.hpp"
#include "../domain/model/product-model.hpp"
#include "../domain/model/buy-request-model.hpp"
#include "../domain/model/discount-model.hpp"

class InvoiceEmitterController
{
private:
    CompanyModel *companyModel;
    vector<ProductModel *> productsModel;
    vector<BuyRequestModel *> buyRequestsModel;
    vector<DiscountModel *> discountsModel;

public:
    InvoiceEmitterController(CompanyDto *companyDto, vector<ProductDto *> productsDto, vector<BuyRequestDto *> buyRequestsDto, vector<DiscountDto *> discountsDto);
    Invoice *Execute();
};

#endif
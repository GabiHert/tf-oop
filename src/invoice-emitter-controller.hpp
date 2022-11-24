#ifndef Invoice_emitter_h
#define Invoice_emitter_h
//#pragma once

#include "company-dto.hpp"
#include "product-dto.hpp"
#include "buy-request-dto.hpp"
#include "discount-dto.hpp"
#include "invoice.hpp"
#include "company-model.hpp"
#include "product-model.hpp"
#include "buy-request-model.hpp"
#include "discount-model.hpp"

class InvoiceEmitterController
{
private:
    CompanyModel *_companyModel;
    vector<ProductModel *> *_productsModel;
    vector<BuyRequestModel *> *_buyRequestsModel;
    vector<DiscountModel *> *_discountsModel;

public:
    InvoiceEmitterController(CompanyDto *companyDto, vector<ProductDto *> *productsDto, vector<BuyRequestDto *> *buyRequestsDto, vector<DiscountDto *> *discountsDto);
    Invoice *Execute();
};

#endif
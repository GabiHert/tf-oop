#include "invoice-emitter-controller.hpp"
#include "buy-register.hpp"
#include "register-buy-use-case.hpp"
#include "apply-discount-use-case.hpp"
#include <iostream>
using namespace std;

InvoiceEmitterController::InvoiceEmitterController(CompanyDto *companyDto, vector<ProductDto *> *productsDto, vector<BuyRequestDto *> *buyRequestsDto, vector<DiscountDto *> *discountsDto)
{
    this->_companyModel = new CompanyModel(companyDto);

    this->_productsModel = new vector<ProductModel *>();
    this->_buyRequestsModel = new vector<BuyRequestModel *>();
    this->_discountsModel = new vector<DiscountModel *>();

    for (int i = 0; i < int(productsDto->size()); i++)
    {
        this->_productsModel->push_back(new ProductModel(productsDto->at(i)));
    }

    for (int i = 0; i < int(buyRequestsDto->size()); i++)
    {
        this->_buyRequestsModel->push_back(new BuyRequestModel(buyRequestsDto->at(i)));
    }

    for (int i = 0; i < int(discountsDto->size()); i++)
    {
        this->_discountsModel->push_back(new DiscountModel(discountsDto->at(i)));
    }
};

Invoice *InvoiceEmitterController::Execute()
{
    cout << "InvoiceEmitterController::Execute - Process started" << endl;

    vector<BuyRegister *> *buyRegisters = new vector<BuyRegister *>();

    for (int i = 0; i < int(this->_buyRequestsModel->size()); i++)
    {
        cout << "InvoiceEmitterController::Execute - RegisterBuyUseCase execution " << i << endl;

        RegisterBuyUseCase::Execute(buyRegisters, this->_buyRequestsModel->at(i), this->_productsModel);
    }

    ApplyDiscountUseCase::Execute(buyRegisters, this->_discountsModel);

    cout << "InvoiceEmitterController::Execute - Process finished" << endl;

    return new Invoice(buyRegisters, this->_companyModel);
};

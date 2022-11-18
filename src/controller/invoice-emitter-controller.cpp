#include "./invoice-emitter-controller.hpp"
#include "../domain/invoice/buy-register.hpp"
#include "../usecase/register-buy-use-case.hpp"
#include "../usecase/apply-discount-use-case.hpp"
#include <iostream>
using namespace std;

InvoiceEmitterController::InvoiceEmitterController(CompanyDto *companyDto, vector<ProductDto *> productsDto, vector<BuyRequestDto *> buyRequestsDto, vector<DiscountDto *> discountsDto)
{
    this->_companyModel = new CompanyModel(companyDto);

    for (int i = 0; i < int(productsDto.size()); i++)
    {
        this->_productsModel.push_back(new ProductModel(productsDto[i]));
    }

    for (int i = 0; i < int(buyRequestsDto.size()); i++)
    {
        this->_buyRequestsModel.push_back(new BuyRequestModel(buyRequestsDto[i]));
    }

    for (int i = 0; i < int(discountsDto.size()); i++)
    {
        this->_discountsModel.push_back(new DiscountModel(discountsDto[i]));
    }
};

Invoice *InvoiceEmitterController::Execute()
{
    cout << "InvoiceEmitterController::Execute - Process started" << endl;

    vector<BuyRegister *> buyRegisters;

    for (int i = 0; i < int(this->_buyRequestsModel.size()); i++)
    {
        cout << "InvoiceEmitterController::Execute - RegisterBuyUseCase execution " << i << endl;

        RegisterBuyUseCase::Execute(buyRegisters, this->_buyRequestsModel[i], this->_productsModel);
    }

    for (int i = 0; i < int(buyRegisters.size()); i++)
    {
        cout << "InvoiceEmitterController::Execute - ApplyDiscountUseCase execution " << i << endl;

        ApplyDiscountUseCase::Execute(buyRegisters, i, this->_discountsModel);
    }

    cout << "InvoiceEmitterController::Execute - Process finished" << endl;

    return new Invoice(buyRegisters, this->_companyModel);
};

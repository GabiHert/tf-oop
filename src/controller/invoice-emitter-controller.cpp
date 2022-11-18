#include "./invoice-emitter-controller.hpp"
#include "../domain/invoice/buy-register.hpp"
#include "../usecase/register-buy-use-case.hpp"
#include "../usecase/apply-discount-use-case.hpp"

InvoiceEmitterController::InvoiceEmitterController(CompanyDto *companyDto, vector<ProductDto *> productsDto, vector<BuyRequestDto *> buyRequestsDto, vector<DiscountDto *> discountsDto)
{
    this->_companyModel = new CompanyModel(companyDto);

    for (int i = 0; i < productsDto.size(); i++)
    {
        this->_productsModel.push_back(new ProductModel(productsDto[i]));
    }

    for (int i = 0; i < buyRequestsDto.size(); i++)
    {
        this->_buyRequestsModel.push_back(new BuyRequestModel(buyRequestsDto[i]));
    }

    for (int i = 0; i < discountsDto.size(); i++)
    {
        this->_discountsModel.push_back(new DiscountModel(discountsDto[i]));
    }
};

Invoice *InvoiceEmitterController::Execute()
{
    vector<BuyRegister *> buyRegisters;

    for (int i = 0; i < this->_buyRequestsModel.size(); i++)
    {
        RegisterBuyUseCase::Execute(buyRegisters, this->_buyRequestsModel[i], this->_productsModel);
    }

    for (int i = 0; i < buyRegisters.size(); i++)
    {
        ApplyDiscountUseCase::Execute(buyRegisters, i, this->_discountsModel);
    }

    return new Invoice(buyRegisters, this->_companyModel);
};

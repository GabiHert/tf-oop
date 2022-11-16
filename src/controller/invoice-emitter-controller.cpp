#include "./invoice-emitter-controller.hpp"
#include "../domain/invoice/buy-register.hpp"
#include "../usecase/register-buy-use-case.hpp"
#include "../usecase/apply-discount-use-case.hpp"

InvoiceEmitterController::InvoiceEmitterController(CompanyDto *companyDto, vector<ProductDto *> productsDto, vector<BuyRequestDto *> buyRequestsDto, vector<DiscountDto *> discountsDto)
{
    this->companyModel = new CompanyModel(companyDto);

    for (int i = 0; i < productsDto.size(); i++)
    {
        this->productsModel.push_back(new ProductModel(productsDto[i]));
    }

    for (int i = 0; i < buyRequestsDto.size(); i++)
    {
        this->buyRequestsModel.push_back(new BuyRequestModel(buyRequestsDto[i]));
    }

    for (int i = 0; i < discountsDto.size(); i++)
    {
        this->discountsModel.push_back(new DiscountModel(discountsDto[i]));
    }
};

InvoiceModel InvoiceEmitterController::Execute()
{
    BuyRegister *buyRegisters[this->buyRequestsModel.size()];

    for (int i = 0; i < this->buyRequestsModel.size(); i++)
    {
        RegisterBuyUseCase::Execute(buyRegisters[i], this->buyRequestsModel.at(i), this->productsModel);
        ApplyDiscountUseCase::Execute(buyRegisters[i], this->discountsModel);
    }
};

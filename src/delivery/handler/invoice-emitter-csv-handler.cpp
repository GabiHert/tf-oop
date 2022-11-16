#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "../../delivery/handler/invoice-emitter-csv-handler.hpp"
#include "../../domain/dto/company-dto.hpp"
#include "../../domain/dto/product-dto.hpp"
#include "../../domain/dto/buy-request-dto.hpp"
#include "../../domain/dto/discount-dto.hpp"
#include "../../utils/utils.hpp"
#include "../../controller/invoice-emitter-controller.hpp"

void InvoiceEmitterCsv::Execute(string buyRequestsDataFilePath, string companyDataFilePath, string productDataFilePath, string discountDataFilePath)
{
    ifstream companyDataFile, productDataFile, discountDataFile, buyRequestsDataFile;
    companyDataFile.open(companyDataFilePath, ios::in);
    productDataFile.open(productDataFilePath, ios::in);
    discountDataFile.open(discountDataFilePath, ios::in);
    buyRequestsDataFile.open(buyRequestsDataFilePath, ios::in);

    // numCupom prdutos
    vector<string> companyData, productData, discountData, buyRequestsData;
    string aux;

    if (!companyDataFile.is_open())
        return;
    do
    {
        companyData.push_back(aux);

        getline(companyDataFile, aux);
    } while (aux != "");

    if (!productDataFile.is_open())
        return;
    do
    {
        productData.push_back(aux);
        getline(productDataFile, aux);
    } while (aux != "");

    if (!discountDataFile.is_open())
        return;
    do
    {
        discountData.push_back(aux);
        getline(discountDataFile, aux);
    } while (aux != "");

    if (!buyRequestsDataFile.is_open())
        return;
    do
    {
        buyRequestsData.push_back(aux);
        getline(buyRequestsDataFile, aux);
    } while (aux != "");

    vector<BuyRequestDto *> buyRequestsDto;
    for (int i = 0; i < buyRequestsData.size(); i++)
    {
        vector<string> buyRequests = splitStr(buyRequestsData.at(i), ";");
        buyRequestsDto.push_back(new BuyRequestDto(buyRequests.at(0), buyRequests.at(1)));
    }

    vector<string> company = splitStr(companyData.at(0), ";");
    CompanyDto *companyDto = new CompanyDto(company[0], company[1], company[2], company[3]);

    vector<ProductDto *> productsDto;
    for (int i = 0; i < productData.size(); i++)
    {
        vector<string> productsData = splitStr(productData.at(i), ";");
        productsDto.push_back(new ProductDto(productsData.at(0), productsData.at(1), productsData.at(2), productsData.at(3), productsData.at(4), productsData.at(5)));
    }

    vector<DiscountDto *> discountsDto;
    for (int i = 0; i < discountData.size(); i++)
    {
        vector<string> discount = splitStr(discountData.at(i), ";");
        DiscountDto *discountDto = new DiscountDto(discount[0], discount[1], discount[2], discount[3], discount[4], discount[5]);
    }

    InvoiceEmitterController invoiceEmitterController = InvoiceEmitterController(companyDto, productsDto, buyRequestsDto, discountsDto);

    InvoiceModel invoiceModel = invoiceEmitterController.Execute();
}

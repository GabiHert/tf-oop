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
#include "../../domain/dto/address-dto.hpp"
using namespace std;

void InvoiceEmitterCsv::execute(string buyRequestsDataFilePath, string companyDataFilePath, string productDataFilePath, string discountDataFilePath)
{
    cout << "InvoiceEmitterCsv::Execute - Process started" << endl;
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

    cout << "InvoiceEmitterCsv::Execute - company data file read" << endl;

    if (!productDataFile.is_open())
        return;
    do
    {
        productData.push_back(aux);
        getline(productDataFile, aux);
    } while (aux != "");

    cout << "InvoiceEmitterCsv::Execute - product data file read" << endl;

    if (!discountDataFile.is_open())
        return;
    do
    {
        discountData.push_back(aux);
        getline(discountDataFile, aux);
    } while (aux != "");

    cout << "InvoiceEmitterCsv::Execute - discount data file read" << endl;

    if (!buyRequestsDataFile.is_open())
        return;
    do
    {
        buyRequestsData.push_back(aux);
        getline(buyRequestsDataFile, aux);
    } while (aux != "");

    cout << "InvoiceEmitterCsv::Execute - buy requests data file read" << endl;

    vector<BuyRequestDto *> buyRequestsDto;
    for (int i = 0; i < buyRequestsData.size(); i++)
    {
        cout << "InvoiceEmitterCsv::Execute - buyRequestData" << i << buyRequestsData.at(i) << endl;

        vector<string> buyRequests = splitStr(buyRequestsData.at(i), ";");
        buyRequestsDto.push_back(new BuyRequestDto(buyRequests.at(0), buyRequests.at(1)));
    }

    vector<string> company = splitStr(companyData.at(0), ";");
    vector<string> address = splitStr(company[3], ":");
    AddressDto *addressDto = new AddressDto(address[0], address[1], address[2], address[3], address[4], address[5], address[6], address[7]);
    CompanyDto *companyDto = new CompanyDto(company[0], company[1], company[2], addressDto);

    vector<ProductDto *> productsDto;
    for (int i = 0; i < productData.size(); i++)
    {
        cout << "InvoiceEmitterCsv::Execute - productData" << i << productData.at(i) << endl;

        vector<string> productsData = splitStr(productData.at(i), ";");
        productsDto.push_back(new ProductDto(productsData.at(0), productsData.at(1), productsData.at(2), productsData.at(3), productsData.at(4), productsData.at(5)));
    }

    vector<DiscountDto *> discountsDto;
    for (int i = 0; i < discountData.size(); i++)
    {
        cout << "InvoiceEmitterCsv::Execute - discountData" << i << discountData.at(i) << endl;

        vector<string> discount = splitStr(discountData.at(i), ";");
        DiscountDto *discountDto = new DiscountDto(discount[0], discount[1], discount[2], discount[3], discount[4], discount[5]);
    }

    InvoiceEmitterController invoiceEmitterController = InvoiceEmitterController(companyDto, productsDto, buyRequestsDto, discountsDto);

    Invoice *invoice = invoiceEmitterController.Execute();

    cout << "InvoiceEmitterCsv::Execute - Process finished" << endl;
}

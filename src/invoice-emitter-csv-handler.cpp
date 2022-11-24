#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "invoice-emitter-csv-handler.hpp"
#include "company-dto.hpp"
#include "product-dto.hpp"
#include "buy-request-dto.hpp"
#include "discount-dto.hpp"
#include "utils.hpp"
#include "invoice-emitter-controller.hpp"
#include "address-dto.hpp"
using namespace std;

void InvoiceEmitterCsv::Execute(string buyRequestsDataFilePath, string companyDataFilePath, string productDataFilePath, string discountDataFilePath)
{
    cout << "InvoiceEmitterCsv::Execute - Process started" << endl;
    ifstream companyDataFile(companyDataFilePath), productDataFile(productDataFilePath), discountDataFile(discountDataFilePath), buyRequestsDataFile(buyRequestsDataFilePath);

    cout << "InvoiceEmitterCsv::Execute - .open done" << endl;

    // numCupom prdutos
    vector<string> companyData, productData, discountData, buyRequestsData;
    string aux;

    cout << "InvoiceEmitterCsv::Execute - declarations done" << endl;

    while (getline(companyDataFile, aux))
    {
        cout << "InvoiceEmitterCsv::Execute - reading company data : " << aux << endl;
        companyData.push_back(aux);
    }

    cout << "InvoiceEmitterCsv::Execute - company data file read" << endl;

    while (getline(productDataFile, aux))
    {
        cout << "InvoiceEmitterCsv::Execute - reading product data : " << aux << endl;
        productData.push_back(aux);
    }

    cout << "InvoiceEmitterCsv::Execute - product data file read" << endl;

    while (getline(discountDataFile, aux))
    {
        cout << "InvoiceEmitterCsv::Execute - reading discountDataFile : " << aux << endl;

        discountData.push_back(aux);
    }

    cout << "InvoiceEmitterCsv::Execute - discount data file read" << endl;

    while (getline(buyRequestsDataFile, aux))
    {
        cout << "InvoiceEmitterCsv::Execute - reading buyRequestsDataFile : " << aux << endl;

        buyRequestsData.push_back(aux);
    }

    cout << "InvoiceEmitterCsv::Execute - buy requests data file read" << endl;

    vector<BuyRequestDto *> *buyRequestsDto = new vector<BuyRequestDto *>();
    for (int i = 0; i < int(buyRequestsData.size()); i++)
    {
        cout << "InvoiceEmitterCsv::Execute - buyRequestData: " << buyRequestsData.at(i) << endl;

        vector<string> buyRequests = splitStr(buyRequestsData.at(i), ";");
        buyRequestsDto->push_back(new BuyRequestDto(buyRequests.at(0), buyRequests.at(1)));
    }

    vector<string> company = splitStr(companyData.at(0), ";");
    vector<string> address = splitStr(company[3], ":");
    AddressDto *addressDto = new AddressDto(address[0], address[1], address[2], address[3], address[4], address[5], address[6], address[7]);
    CompanyDto *companyDto = new CompanyDto(company[0], company[1], company[2], addressDto);

    vector<ProductDto *> *productsDto = new vector<ProductDto *>();

    for (int i = 0; i < int(productData.size()); i++)
    {
        cout << "InvoiceEmitterCsv::Execute - productData" << i << productData.at(i) << endl;

        vector<string> productsData = splitStr(productData.at(i), ";");
        productsDto->push_back(new ProductDto(productsData.at(0), productsData.at(1), productsData.at(2), productsData.at(3), productsData.at(4), productsData.at(5)));
    }

    vector<DiscountDto *> *discountsDto = new vector<DiscountDto *>();
    for (int i = 0; i < int(discountData.size()); i++)
    {
        cout << "InvoiceEmitterCsv::Execute - discountData" << i << discountData.at(i) << endl;

        vector<string> discount = splitStr(discountData.at(i), ";");
        discountsDto->push_back(new DiscountDto(discount[0], discount[1], discount[2], discount[3], discount[4], discount[5]));
    }

    InvoiceEmitterController invoiceEmitterController = InvoiceEmitterController(companyDto, productsDto, buyRequestsDto, discountsDto);

    Invoice *invoice = invoiceEmitterController.Execute();

    cout << "InvoiceEmitterCsv::Execute - Process finished" << endl;

    cout << invoice->toString() << endl;
}

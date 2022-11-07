#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "delivery/invoice-emmiter-csv.hpp"

void InvoiceEmitterCsv::Execute(string companyDataFilePath, string productDataFilePath, string discountDataFilePath)
{
    ifstream companyDataFile, productDataFile, discountDataFile;
    companyDataFile.open(companyDataFilePath, ios::in);
    productDataFile.open(productDataFilePath, ios::in);
    discountDataFile.open(discountDataFilePath, ios::in);

    string companyData, productData, discountData;

    if (!companyDataFile.is_open())
        return;
    getline(companyDataFile, companyData);

    if (!productDataFile.is_open())
        return;
    getline(productDataFile, companyData);

    if (!discountDataFile.is_open())
        return;
    getline(discountDataFile, companyData);

    string companyData, productData, discountData;
}

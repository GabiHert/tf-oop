#ifndef utils_h
#define utils_h
//#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<string> splitStr(string str, string delim);

string truncFloatToStr(string str, int decimalPlaces);
string truncFloatToStr(float f, int decimalPlaces);
string strSpaceGen(int n);
#endif
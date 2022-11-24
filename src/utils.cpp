#include "utils.hpp"

vector<string> splitStr(string str, string delim)
{
    int start = 0;
    int end = str.find(delim);
    vector<string> strVector;

    while (end != -1)
    {
        strVector.push_back(str.substr(start, end - start));
        start = end + delim.size();
        end = str.find(delim, start);
    }
    strVector.push_back(str.substr(start, end - start));

    return strVector;
}

string truncFloatToStr(string str, int decimalPlaces)
{
    int index = 0;
    while (str[index] != '.')
    {
        if (index > str.length())
            return str;
        index++;
    }

    return str.substr(0, index) + str.substr(index, decimalPlaces + 1);
}

string truncFloatToStr(float f, int decimalPlaces)
{
    string str = to_string(f);
    int index = 0;
    while (str[index] != '.')
    {
        if (index > str.length())
            return str;
        index++;
    }

    return str.substr(0, index) + str.substr(index, decimalPlaces + 1);
}

string strSpaceGen(int n)
{
    if (n < 0)
        n = 0;
    string str;
    for (int i = 0; i < n; i++)
    {
        str += " ";
    }
    return str;
};

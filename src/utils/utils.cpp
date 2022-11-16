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

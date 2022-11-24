#ifndef sell_amount_h
#define sell_amount_h
#include <string>
using namespace std;

class SellAmount
{
private:
    static string Unit;
    static string Bulk;

protected:
    string name;

public:
    static string getBulk() { return Bulk; };
    static string getUnit() { return Unit; };
    string getName() { return name; };
    SellAmount(string name);
};

#endif
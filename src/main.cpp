#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    ifstream arq;
    cout << "Abrindo arq" << endl;
    arq.open("../teste.csv", ios::in);
    if (!arq.is_open())
        return 1;
    string header, result;
    do
    {
        getline(arq, header);
        result += header + '\n';
    } while (arq.good());
    cout << result << endl;
};
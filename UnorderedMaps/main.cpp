#include "Unordered_Map.h"
#include <iostream>

using namespace std;

int main()
{
    Unordered_Map<string, int> balance(1);
    balance["Mick"] = 50;
    balance["John"] = 60;
    balance["Rallod"] = 70;
    balance["David"] = 80;
    balance["Daphlen"] = 90;
    balance.Print();
    balance["Wang"] = 100;
    balance.Print();
    return 0;
}

#include "Unordered_Map.h"
#include <iostream>

using namespace std;

int main()
{
    Unordered_Map<string, int> balance;
    balance["123"] = 456;
    cout << balance["123"];
    return 0;
}

#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person<float> p1("A", 170, 50);
    Person<float> p2("B", 160, 30);
    cout << p1 + p2;
    return 0;
}
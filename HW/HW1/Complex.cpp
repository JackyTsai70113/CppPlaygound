#include <iostream>
#include "Complex.h"

int main()
{
    Complex<float> c0;
    cin >> c0;
    cout << "Your input c0: " << c0 << endl;

    Complex<float> c1(1, 1);
    Complex<float> c2(2, 2);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    Complex<float> c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl;
    c3 = c1 - c2;
    cout << "c1 - c2: " << c3 << endl;
    c3 = c1 * c2;
    cout << "c1 * c2: " << c3 << endl;
    c3 = c1 / c2;
    cout << "c1 / c2: " << c3 << endl;

    cout << "c1.norm(): " << c1.norm() << endl;
    c3 = c1.conjugate();
    cout << "c1.conjugate(): " << c3 << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;

    return 0;
}
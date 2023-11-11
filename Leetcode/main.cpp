#include <iostream>
#include "0007.ReverseClass.h"
#include "0067.AddBinaryClass.h"
#include "0125.IsPalindromeClass.h"
#include "0172.TrailingZeroesClass.h"

using namespace std;

int main()
{
    cout << TrailingZeroesClass().trailingZeroes(3) << endl;
    cout << IsPalindromeClass().isPalindrome("0P") << endl;
    cout << "A man, a plan, a canal: Panama" << endl;
    cout << AddBinaryClass().addBinary("11", "1") << endl;
    cout << ReverseClass().reverse(-1234567) << endl;
}
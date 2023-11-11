#ifndef IsPalindromeClass_H_INCLUDED
#define IsPalindromeClass_H_INCLUDED

#include <string>
#include <cctype>

using namespace std;

class IsPalindromeClass
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        while (true)
        {
            while (!isalnum(s[l]) && l + 1 < (int)s.length())
                l++;
            while (!isalnum(s[r]) && r - 1 >= 0 && l < r)
                r--;
            if (l >= r)
                break;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

#endif
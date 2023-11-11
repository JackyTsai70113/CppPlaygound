#ifndef ReverseClass_H_INCLUDED
#define ReverseClass_H_INCLUDED

#include <string>
#include <limits.h>

using namespace std;

class ReverseClass
{
public:
    int reverse(int x)
    {
        string str = to_string(x);
        int res = 0;
        if (x < 0)
            str = str.substr(1, str.length() - 1);
        for (int i = str.length() - 1; i >= 0; --i)
        {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' >= 2))
                return 0;
            res = res * 10 - '0' + str[i];
        }
        if (x < 0)
            res = -res;
        return res;
    }
};

#endif
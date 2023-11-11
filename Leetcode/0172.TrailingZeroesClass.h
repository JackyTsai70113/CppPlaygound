#ifndef TrailingZeroesClass_H_INCLUDED
#define TrailingZeroesClass_H_INCLUDED

#include <algorithm>

class TrailingZeroesClass
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        for (int i = 1; i <= 6; ++i)
        {
            res += n / pow(5, i);
        }
        return res;
    }
};

#endif // TrailingZeroesClass_H_INCLUDED
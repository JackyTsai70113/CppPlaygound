#ifndef AddBinaryClass_H_INCLUDED
#define AddBinaryClass_H_INCLUDED

#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class AddBinaryClass
{
public:
    string addBinary(string a, string b)
    {
        list<char> v;
        int ai = a.length() - 1, bi = b.length() - 1, c = 0;
        while (ai >= 0 || bi >= 0)
        {
            int v1 = ai >= 0 ? a[ai] - '0' : 0;
            int v2 = bi >= 0 ? b[bi] - '0' : 0;
            int val = v1 + v2 + c;
            v.push_front((char)(val % 2 + '0'));
            c = val / 2;
            ai--;
            bi--;
        }
        if (c > 0)
        {
            v.push_front('1');
        }
        return string(v.begin(), v.end());
    }
};

#endif

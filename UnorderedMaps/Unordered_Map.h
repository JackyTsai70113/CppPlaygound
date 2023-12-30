#ifndef UNORDER_MAP_H_INCLUDED
#define UNORDER_MAP_H_INCLUDED

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

template <typename T1, typename T2>
struct Data
{
    T1 Key;
    T2 Value;
};

template <typename T1, typename T2>
class Unordered_Map
{
private:
    int Len;
    Data<T1, T2> *Pointer;
    int Hash_Func_Div(T1);
    int Hash_Func_Mul(T1);

public:
    T2 &operator[](T1);
    Unordered_Map(int = 128);
};

template <typename T1, typename T2>
Unordered_Map<T1, T2>::Unordered_Map(int len)
{
    Len = len;
    Pointer = (Data<T1, T2> *)malloc(sizeof(Data<T1, T2>) * Len);
}

template <typename T1, typename T2>
T2 &Unordered_Map<T1, T2>::operator[](T1 input)
{
    int index = Hash_Func_Mul(input);
    Pointer[index].Key = input;
    return Pointer[index].Value;
}

template <typename T1, typename T2>
int Unordered_Map<T1, T2>::Hash_Func_Div(T1 input)
{
    long long int sum = 0;
    for (char c : input)
    {
        sum += c;
    }
    return sum % Len;
}

template <typename T1, typename T2>
int Unordered_Map<T1, T2>::Hash_Func_Mul(T1 input)
{
    long long int sum = 0;
    double c = (sqrt(5) - 1) / 2.0;
    int temp = 1;
    for (char c : input)
    {
        sum += temp * c;
        temp *= 256;
    }
    // get fraction
    double frac = c * sum - (int)(c * sum);
    int index = frac * Len;
    return index;
}

#endif // UNORDER_MAP_H_INCLUDED
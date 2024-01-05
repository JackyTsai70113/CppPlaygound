#ifndef UNORDER_MAP_H_INCLUDED
#define UNORDER_MAP_H_INCLUDED

#include <iostream>
#include <math.h>
#include <vector>
#include <list>
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
    int len;
    int amount;
    vector<list<Data<T1, T2>>> Datas;
    int Hash_Func_Div(T1);
    int Hash_Func_Mul(T1);
    // 將原有的 hash table 擴增為兩倍空間
    void Rehashing();

public:
    T2 &operator[](T1);
    void Print();
    Unordered_Map(int = 128);
};

template <typename T1, typename T2>
Unordered_Map<T1, T2>::Unordered_Map(int m)
{
    len = m;
    amount = 0;
    Datas.resize(m);
}

template <typename T1, typename T2>
void Unordered_Map<T1, T2>::Print()
{
    for (int i = 0; i < Datas.size(); i++){
        cout << i << "-th: ";
        for (auto iter = Datas[i].begin(); iter != Datas[i].end(); iter++)
        {
            T1 key = iter->Key;
            T2 value = iter->Value;
            cout << "{" << key << ", " << value << "}";
        }
        cout << endl;
    }
}

template <typename T1, typename T2>
T2 &Unordered_Map<T1, T2>::operator[](T1 input)
{
    int index = Hash_Func_Mul(input);
    for (auto iter = Datas[index].begin(); iter != Datas[index].end(); iter++)
    {
        if ((*iter).Key == input)
        {
            return (*iter).Value;
        }
    }
    // not found data
    amount++;
    if(amount / len > 5){
        Rehashing();
        index = Hash_Func_Mul(input);
    }
    Datas[index].push_back(Data<T1, T2>{input, 0});
    return Datas[index].back().Value;
}

template <typename T1, typename T2>
int Unordered_Map<T1, T2>::Hash_Func_Div(T1 input)
{
    long long int sum = 0;
    for (char c : input)
    {
        sum += c;
    }
    return sum % len;
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
    int index = frac * len;
    return index;
}

template <typename T1, typename T2>
void Unordered_Map<T1, T2>::Rehashing()
{
    len *= 2;
    vector<list<Data<T1, T2>>> new_data(len);
    for (int i = 0; i < Datas.size(); i++){
        for (auto iter = Datas[i].begin(); iter != Datas[i].end(); iter++)
        {
            T1 key = iter->Key;
            T2 value = iter->Value;
            int index = Hash_Func_Div(key);
            new_data[index].push_back(Data<T1, T2>{key, value});
        }
    }
    Datas = new_data;
}

#endif // UNORDER_MAP_H_INCLUDED
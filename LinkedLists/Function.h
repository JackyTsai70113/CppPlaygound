#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

// 迭代器 it 向後移 n 步
template <typename T>
void Advance(T iter, const int &distance)
{
    for (int i = 0; i < distance; ++i){
        iter++;
    }
}

// 計算兩迭代器之間的距離
template <typename T>
void Distance(T iter1, T iter2)
{
    int res = 0;
    while(iter1 != iter2){
        res++;
        iter1++;
    }
    return res;
}

template <typename T1, typename T2>
T1 Begin(T2 container)
{
    return container.Begin();
}

template <typename T1, typename T2>
T1 End(T2 container)
{
    return container.End();
}

template <typename T>
T Prev(T iter)
{
    iter--;
    return iter;
}

template <typename T>
T Next(T iter)
{
    iter++;
    return iter;
}

#endif
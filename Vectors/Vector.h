#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdlib.h>

template <typename T>
class Vector
{
private:
    // 指標
    T *Pointer;
    // 容量
    int Capacity;
    // 長度
    int Len;

public:
    class Iterator
    {
    private:
        T *iter;

    public:
        Iterator(T * = nullptr);
        // ++Iterator
        void operator++();
        // --Iterator
        void operator--();
        // Iterator++
        void operator++(int);
        // Iterator--
        void operator--(int);
        bool operator==(Iterator);
        bool operator!=(Iterator);
        bool operator>(Iterator);
        bool operator<(Iterator);
        bool operator>=(Iterator);
        bool operator<=(Iterator);
        void operator=(Iterator);
        int operator-(Iterator);
        Iterator operator+(int);
        Iterator operator-(int);
        T &operator*();
    };
    // 建構式
    Vector(int = 0);
    // 解構式
    ~Vector();
    // 回傳第一個元素的迭代器
    Iterator Begin();
    // 回傳最後一個元素
    Iterator End();
    // 回傳第一個元素
    T Front();
    // 回傳最後一個元素
    T Back();
    // 取出特定索引值的資料
    T &At(int);
    // 運算值重載
    T &operator[](int);
    // 回傳目前陣列長度
    int Size();
    // 判斷是否為空
    bool Empty();
    // 尾端新增
    void Push_Back(T);
    // 尾端刪除
    void Pop_Back();
    // 在特定索引值插入迭代器
    void Insert(Iterator, T);
    // 刪除特定迭代器
    void Erase(Iterator);
    // 刪除區間中的資料
    void Erase(Iterator, Iterator);
    // 清空所有資料
    void Clear();
    // 擴展陣列容量
    void Reserve(int);
    // 修改陣列長度
    void Resize(int);
};

/// @brief 搜尋 Vector 中的資料
/// @param  特定資料
/// @return 回傳搜尋到的第一個特定資料迭代器
template <typename T>
typename Vector<T>::Iterator Find(Vector<T> &v, T val)
{
    for (typename Vector<T>::Iterator iter = v.Begin(); iter != v.End(); ++iter)
    {
        if (*iter == val)
            return iter;
    }
    return v.End();
}

// /// @brief 刪除特定資料, 把特定區間中的資料移到最後面
// /// @param  特定資料
// /// @return 第一個特定資料的位置
template <typename T>
typename Vector<T>::Iterator Remove(Vector<T> &v, T val)
{
    int counts = 0;
    for (typename Vector<T>::Iterator iter = v.Begin(); iter != v.End(); ++iter)
    {
        if (*iter == val)
            continue;
        *(v.Begin() + counts) = *iter;
        counts++;
    }
    for (typename Vector<T>::Iterator iter = (v.Begin() + counts); iter != v.End(); iter++)
    {
        *iter = val;
    }
    return v.Begin() + counts;
}

template <typename T>
Vector<T>::Iterator::Iterator(T *pointer)
{
    iter = pointer;
}

template <typename T>
void Vector<T>::Iterator::operator++()
{
    iter++;
}

template <typename T>
void Vector<T>::Iterator::operator--()
{
    iter--;
}

template <typename T>
void Vector<T>::Iterator::operator++(int)
{
    iter++;
}

template <typename T>
void Vector<T>::Iterator::operator--(int)
{
    iter--;
}

template <typename T>
bool Vector<T>::Iterator::operator==(Vector<T>::Iterator iter2)
{
    return iter == iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(Vector<T>::Iterator iter2)
{
    return iter != iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator>(Vector<T>::Iterator iter2)
{
    return iter > iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator<(Vector<T>::Iterator iter2)
{
    return iter < iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator>=(Vector<T>::Iterator iter2)
{
    return iter >= iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator<=(Vector<T>::Iterator iter2)
{
    return iter <= iter2.iter;
}

template <typename T>
void Vector<T>::Iterator::operator=(Vector<T>::Iterator iter2)
{
    iter = iter2.iter;
}

template <typename T>
int Vector<T>::Iterator::operator-(Iterator iter2)
{
    return iter - iter2.iter;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int offset)
{
    Iterator result(iter + offset);
    return result;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int offset)
{
    Iterator result(iter - offset);
    return result;
}

template <typename T>
T &Vector<T>::Iterator::operator*()
{
    return *iter;
}

template <typename T>
Vector<T>::Vector(int length)
{
    if (length == 0)
    {
        Pointer = nullptr;
        // or Pointer = 0
        Capacity = 0;
        Len = 0;
    }
    else
    {
        Capacity = length;
        Len = length;
        Pointer = (T *)calloc(length, sizeof(T));
    }
}

template <typename T>
Vector<T>::~Vector()
{
    if (Capacity == 0)
        return;
    free(Pointer);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Begin()
{
    Iterator result(Pointer);
    return result;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::End()
{
    Iterator result(Pointer + Len);
    return result;
}

template <typename T>
T Vector<T>::Front()
{
    return *Pointer;
}

template <typename T>
T Vector<T>::Back()
{
    return *(Pointer + Len - 1);
}

template <typename T>
T &Vector<T>::At(int i)
{
    return *(Pointer + i);
}

template <typename T>
T &Vector<T>::operator[](int i)
{
    return *(Pointer + i);
}

template <typename T>
int Vector<T>::Size()
{
    return Len;
}

template <typename T>
bool Vector<T>::Empty()
{
    return Len == 0;
}

template <typename T>
void Vector<T>::Push_Back(T data)
{
    if (Len == Capacity)
    {
        if (Capacity == 0)
            Reserve(1);
        else
            Reserve(Capacity * 2);
    }
    *(Pointer + Len) = data;
    Len++;
}

template <typename T>
void Vector<T>::Pop_Back()
{
    if (Empty())
        return;
    Len--;
}

template <typename T>
void Vector<T>::Insert(Iterator position, T val)
{
    if (position < Begin())
        return;
    if (position > End())
        return;
    if (Len == Capacity)
    {
        if (Capacity == 0)
            Reserve(1);
        else
            Reserve(Capacity * 2);
    }
    for (Iterator cur = End(); cur >= position; cur--)
    {
        *(cur + 1) = *cur;
    }
    *position = val;
    Len++;
}

template <typename T>
void Vector<T>::Erase(Iterator position)
{
    if (Empty())
        return;
    if (position < Begin())
        return;
    if (position >= End())
        return;
    for (Iterator cur = position + 1; cur < End(); cur++)
    {
        *(cur - 1) = *cur;
    }
    Len--;
}

template <typename T>
void Vector<T>::Erase(Iterator first, Iterator last)
{
    if (Empty())
        return;
    if (first < Begin())
        return;
    if (last <= first)
        return;
    if (last >= End())
        return;
    for (Iterator cur = last; cur < End(); cur++)
    {
        *(cur - (last - first)) = *cur;
    }
    Len -= last - first;
}

template <typename T>
void Vector<T>::Clear()
{
    free(Pointer);
    Capacity = 0;
    Len = 0;
    Pointer = nullptr;
}

template <typename T>
void Vector<T>::Reserve(int n)
{
    if (n < Len)
        return;
    Capacity = n;
    T *temp = (T *)malloc(sizeof(T) * Capacity);
    for (int i = 0; i < Len; i++)
    {
        *(temp + i) = *(Pointer + i);
    }
    free(Pointer);
    Pointer = temp;
}
template <typename T>
void Vector<T>::Resize(int n)
{
    if (n < 0)
        return;
    if (n <= Capacity)
        Len = n;
}

#endif // VECTOR_H_INCLUDED
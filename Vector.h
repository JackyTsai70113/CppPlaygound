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
    // 解構式
    int Len;

public:
    // 建構式
    Vector(int = 0);
    // 解構式
    ~Vector();
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
    // 在特定索引值插入資料
    void Insert(int, T);
    // 刪除特定索引值
    void Erase(int);
    // 刪除區間中的資料
    void Erase(int, int);
    // 清空所有資料
    void Clear();
    // 擴展陣列容量
    void Reserve(int);
    // 修改陣列長度
    void Resize(int);
};

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
void Vector<T>::Insert(int index, T data)
{
    if (index > Size())
        return;
    if (index < 0)
        return;
    if (Len == Capacity)
    {
        if (Capacity == 0)
            Reserve(1);
        else
            Reserve(Capacity * 2);
    }
    for (int i = Len - 1; i >= index; i--)
    {
        *(Pointer + i + 1) = *(Pointer + i);
    }
    *(Pointer + index) = data;
    Len++;
}

template <typename T>
void Vector<T>::Erase(int index)
{
    if (Empty())
        return;
    if (index < 0)
        return;
    if (index >= Size())
        return;
    for (int i = index + 1; i < Len; i++)
    {
        *(Pointer + i - 1) = *(Pointer + i);
    }
    Len--;
}

template <typename T>
void Vector<T>::Erase(int first, int last)
{
    if (Empty())
        return;
    if (first < 0)
        return;
    if (last <= first)
        return;
    if (last >= Size())
        return;
    for (int i = last; i < Len; i++)
    {
        *(Pointer + i - (last - first)) = *(Pointer + i);
    }
    Len -= last - first;
}

template <typename T>
void Vector<T>::Clear()
{
    free(Pointer);
    Capacity = 0;
    Len = 0;
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
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class Stack_Array
{
private:
    int Capacity;
    int Top_Index;
    T *Pointer;
    void Double_Capacity();

public:
    Stack_Array(int = 0);
    bool Empty();
    int Size();
    T Top();
    void Push(T);
    void Pop();
    void Print_Stack();
};

template <typename T>
Stack_Array<T>::Stack_Array(int len)
{
    Capacity = len;
    if (len > 0)
    {
        Pointer = (T *)malloc(sizeof(T) * len);
    }
    else
    {
        Pointer = nullptr;
    }
    Top_Index = -1;
}

template <typename T>
inline bool Stack_Array<T>::Empty()
{
    return Top_Index == -1;
}

template <typename T>
inline int Stack_Array<T>::Size()
{
    return Top_Index + 1;
}

template <typename T>
inline T Stack_Array<T>::Top()
{
    if (Empty())
    {
        cout << "Stack is Empty!" << endl;
        return 0;
    }
    return Pointer[Top_Index];
}

template <typename T>
inline void Stack_Array<T>::Push(T val)
{
    if (Size() + 1 > Capacity)
    {
        Double_Capacity();
    }
    Pointer[++Top_Index] = val;
}

template <typename T>
inline void Stack_Array<T>::Pop()
{
    if (Empty())
        return;
    Top_Index--;
}

template <typename T>
inline void Stack_Array<T>::Double_Capacity()
{
    if (Capacity == 0)
    {
        Capacity = 1;
        Pointer = (T *)malloc(sizeof(T));
    }
    else
    {
        Capacity *= 2;
        T *temp = Pointer;
        Pointer = (T *)malloc(sizeof(T) * Capacity);
        for (int i = 0; i <= Top_Index; i++)
            Pointer[i] = temp[i];
        free(temp);
    }
}

template <typename T>
inline void Stack_Array<T>::Print_Stack()
{
    if (Top_Index < 0)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Data: ";
    for (int i = 0; i <= Top_Index; i++)
        cout << *(Pointer + i) << " ";
    cout << endl;
}

#endif // STACK_H_INCLUDED

#ifndef CIRCULAR_LINKED_LIST_H_INCLUDED
#define CIRCULAR_LINKED_LIST_H_INCLUDED

#include "Function.h"
#include "Linked_List.h"
#include <iostream>

using namespace std;

template <typename T>
class Circular_Linked_List
{
private:
    Node<T> *Head;
    int Len;

public:
    // 建構式
    Circular_Linked_List();
    // 印出所有資料
    void Print_List();
    // 新增尾端元素
    void Push_Back(T);
    // 旋轉
    void Rotate(int offset);
    Node<T> *Head_Node();
};

template <typename T>
Circular_Linked_List<T>::Circular_Linked_List()
{
    Head = nullptr;
    Len = 0;
}

template <typename T>
void Circular_Linked_List<T>::Print_List()
{
    if (Head == nullptr)
    {
        cout << "This list is empty!" << endl;
        return;
    }
    Node<T> *cur = Head;
    cout << "Data: [";
    while (cur->Next != Head)
    {
        cout << cur->Data << " ";
        cur = cur->Next;
    }
    cout << cur->Data << "]" << endl;
}

template <typename T>
void Circular_Linked_List<T>::Push_Back(T value)
{
    if (Head == nullptr)
    {
        Head = new Node<T>{value, nullptr, nullptr};
        Head->Prev = Head->Next = Head;
    }
    else
    {
        auto newNode = new Node<T>{value, Head->Prev, Head};
        Head->Prev->Next = newNode;
        Head->Prev = newNode;
    }
    Len++;
}

template <typename T>
void Circular_Linked_List<T>::Rotate(int offset)
{
    if (Head == nullptr)
        return;
    offset %= Len;
    for (int i = 0; i < offset; ++i)
    {
        Head = Head->Next;
    }
}

template <typename T>
Node<T> *Circular_Linked_List<T>::Head_Node()
{
    return Head;
}

#endif // CIRCULAR_LINKED_LIST_H_INCLUDED
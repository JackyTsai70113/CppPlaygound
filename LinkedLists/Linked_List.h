#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
struct Node
{
    T Data;
    Node *Next;
};

template <typename T>
class Linked_List
{
private:
    Node<T> *First;

public:
    Linked_List();
    // 印出所有 Linked List 內的資料
    void Print_List();
    // 在 Linked List 內找尋特定資料，並回傳是第幾筆
    int Search_List(T);
};

template <typename T>
Linked_List<T>::Linked_List()
{
    First = nullptr;
}

template <typename T>
void Linked_List<T>::Print_List()
{
    Node<T> *cur = First;
    while (cur != nullptr)
    {
        cout << cur->Data << " ";
        cur = cur->Next;
    }
    cout << endl;
}

template <typename T>
int Linked_List<T>::Search_List(T target)
{
    int res = -1;
    Node<T> *cur = First;
    while (cur != nullptr)
    {
        res++;
        if (cur->Data == target)
        {
            break;
        }
        cur = cur->Next;
    }
    return res;
}

#endif // VECTOR_H_INCLUDED
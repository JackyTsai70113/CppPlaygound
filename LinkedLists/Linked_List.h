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
    // 新增插入
    // 在特定位置新增資料
    // 新增首項元素
    void Push_Front(T);
    // 新增尾端元素
    void Push_Back(T);
    // 在特定位置刪除資料
    // 刪除首項元素
    void Pop_Front();
    // 刪除尾端元素
    void Pop_Back();
    // 清空所有資料
    void Clear();
    // 反轉鏈結串列
    void Reverse();
};

template <typename T>
Linked_List<T>::Linked_List()
{
    First = nullptr;
}

template <typename T>
void Linked_List<T>::Print_List()
{
    if (First == nullptr)
    {
        cout << "This list is empty!" << endl;
        return;
    }
    Node<T> *cur = First;
    cout << "Data: [";
    while (cur->Next != nullptr)
    {
        cout << cur->Data << " ";
        cur = cur->Next;
    }
    cout << cur->Data << "]" << endl;
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

template <typename T>
void Linked_List<T>::Push_Front(T value)
{
    Node<T> *newNode = new Node<T>{value, First};
    First = newNode;
}

template <typename T>
void Linked_List<T>::Push_Back(T value)
{
    if (First == nullptr)
    {
        Node<T> *newNode = new Node<T>{value, First};
        First = newNode;
    }
    else
    {
        Node<T> *cur = First;
        while (cur->Next != nullptr)
        {
            cur = cur->Next;
        }
        cur->Next = new Node<T>{value, nullptr};
    }
}

template <typename T>
void Linked_List<T>::Pop_Front()
{
    if (First == nullptr)
        return;
    Node<T> *temp = First;
    First = First->Next;
    delete temp;
}

template <typename T>
void Linked_List<T>::Pop_Back()
{
    if (First == nullptr)
        return;
    if (First->Next == nullptr)
    {
        delete First;
        First = nullptr;
        return;
    }
    Node<T> *cur = First;
    while (cur->Next->Next != nullptr)
    {
        cur = cur->Next;
    }
    delete cur->Next;
    cur->Next = nullptr;
}

template <typename T>
void Linked_List<T>::Clear()
{
    while (First != nullptr)
    {
        auto temp = First;
        First = First->Next;
        delete temp;
    }
}

template <typename T>
void Linked_List<T>::Reverse()
{
    if (First == nullptr || First->Next == nullptr)
        return;
    Node<T> *cur = new Node<T>{0, First};
    Node<T> *tail = First;
    while (tail->Next != nullptr)
    {
        auto temp = cur->Next;
        cur->Next = tail->Next;
        tail->Next = tail->Next->Next;
        cur->Next->Next = temp;
    }
    First = cur->Next;
    // Node<T> *previous = nullptr;
    // Node<T> *cur = First;
    // Node<T> *preceding = cur->Next;
    // while (preceding != nullptr)
    // {
    //     cur->Next = previous;
    //     previous = cur;
    //     cur = preceding;
    //     preceding = preceding->Next;
    // }
    // cur->Next = previous;
    // First = cur;
}

#endif // VECTOR_H_INCLUDED
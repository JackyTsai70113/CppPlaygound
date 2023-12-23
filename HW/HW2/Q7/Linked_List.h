#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include "Function.h"
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T Data;
    Node *Prev;
    Node *Next;
};

template <typename T>
class Linked_List
{
private:
    Node<T> *Head;
    Node<T> *Tail;

public:
    class Iterator
    {
        friend Linked_List;

    private:
        Node<T> *iter;

    public:
        Iterator(Node<T> * = nullptr);
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
        void operator=(Iterator);
        int operator-(Iterator);
        Iterator operator+(int);
        Iterator operator-(int);
        T &operator*();
    };
    // 建構式
    Linked_List();
    // 印出所有資料
    void Print_List();
    // 在 Linked List 內找尋特定資料，並回傳是第幾筆
    int Search_List(T);
    // 新增首項元素
    void Push_Front(T);
    // 刪除首項元素
    void Pop_Front();
    // 新增尾端元素
    void Push_Back(T);
    // 刪除尾端元素
    void Pop_Back();
    // 清空所有資料
    void Clear();
    // 反轉鏈結串列
    void Reverse();
    // 在特定位置插入資料
    void Insert(Iterator, const T &);
    // 刪除特定迭代器的資料
    void Erase(Iterator);
    // 刪除特定的資料
    void Remove(T);
    Iterator Begin();
    Iterator End();
};

template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Begin()
{
    return Iterator(Head);
}

template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::End()
{
    return Iterator(nullptr);
}

template <typename T>
Linked_List<T>::Iterator::Iterator(Node<T> *pointer)
{
    iter = pointer;
}

template <typename T>
void Linked_List<T>::Iterator::operator++()
{
    if (iter != nullptr)
        iter = iter->Next;
}

template <typename T>
void Linked_List<T>::Iterator::operator--()
{
    if (iter != nullptr)
        iter = iter->Prev;
}

template <typename T>
void Linked_List<T>::Iterator::operator++(int)
{
    if (iter != nullptr)
        iter = iter->Next;
}

template <typename T>
void Linked_List<T>::Iterator::operator--(int)
{
    if (iter != nullptr)
        iter = iter->Prev;
}

template <typename T>
bool Linked_List<T>::Iterator::operator==(Linked_List<T>::Iterator iter2)
{
    return iter == iter2.iter;
}

template <typename T>
bool Linked_List<T>::Iterator::operator!=(Linked_List<T>::Iterator iter2)
{
    return iter != iter2.iter;
}

template <typename T>
void Linked_List<T>::Iterator::operator=(Linked_List<T>::Iterator iter2)
{
    iter = iter2.iter;
}

template <typename T>
T &Linked_List<T>::Iterator::operator*()
{
    return iter->Data;
}

template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Iterator::operator+(int offset)
{
    Iterator result(iter);
    for (int i = 0; i < offset; ++i)
    {
        if (result->iter == nullptr)
            return result;
        result->iter = result->iter->Next;
    }
    return result;
}

template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Iterator::operator-(int offset)
{
    Iterator result(iter);
    for (int i = 0; i < offset; ++i)
    {
        if (result.iter == nullptr)
            return result;
        result.iter = result.iter->Prev;
    }
    return result;
}

template <typename T>
Linked_List<T>::Linked_List()
{
    Head = nullptr;
    Tail = nullptr;
}

template <typename T>
void Linked_List<T>::Print_List()
{
    if (Head == nullptr)
    {
        cout << "This list is empty!" << endl;
        return;
    }
    Node<T> *cur = Head;
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
    Node<T> *cur = Head;
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
    if (Head == nullptr)
    {
        auto newNode = new Node<T>{value, nullptr, nullptr};
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        Head->Prev = new Node<T>{value, nullptr, Head};
        Head = Head->Prev;
    }
}

template <typename T>
void Linked_List<T>::Push_Back(T value)
{
    if (Head == nullptr)
    {
        auto newNode = new Node<T>{value, nullptr, nullptr};
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        Tail->Next = new Node<T>{value, Tail, nullptr};
        Tail = Tail->Next;
    }
}

template <typename T>
void Linked_List<T>::Pop_Front()
{
    if (Head == nullptr)
        return;
    if (Head == Tail) // only 1 node
    {
        delete Head;
        Head = Tail = nullptr;
        return;
    }
    Head = Head->Next;
    delete Head->Prev;
    Head->Prev = nullptr;
}

template <typename T>
void Linked_List<T>::Pop_Back()
{
    if (Head == nullptr)
        return;

    if (Head == Tail) // only 1 node
    {
        delete Head;
        Head = Tail = nullptr;
        return;
    }
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = nullptr;
}

template <typename T>
void Linked_List<T>::Clear()
{
    while (Head != nullptr)
    {
        auto temp = Head;
        Head = Head->Next;
        delete temp;
    }
    Tail = nullptr;
}

template <typename T>
void Linked_List<T>::Reverse()
{
    if (Head == nullptr || Head == Tail)
        return;
    Node<T> *previous = nullptr;
    Node<T> *cur = Head;
    Node<T> *preceding = Head->Next;
    while (preceding != nullptr)
    {
        cur->Next = previous;
        previous = cur;
        cur = preceding;
        preceding = preceding->Next;
    }
    cur->Prev = previous;
    cur->Next = preceding;
    Head = cur;
}

/// @brief 在特定位置新增資料
/// @param  特定資料
/// @return 回傳搜尋到的第一個特定資料迭代器
template <typename T>
void Linked_List<T>::Insert(Iterator it, const T &val)
{
    // A B, B is provided by user = it
    // A C B
    if (it == Begin())
    {
        Push_Front(val);
        return;
    }
    if (it == End() || it == Iterator(Tail))
    {
        Push_Back(val);
        return;
    }
    Node<T> *newNode = new Node<T>{val, it.iter->Prev, it.iter};
    it.iter->Prev->Next = newNode; // A - B
    it.iter->Prev = newNode;       // C - B
}

/// @brief 在特定位置刪除資料
/// @param  特定資料
/// @return 回傳搜尋到的第一個特定資料迭代器
template <typename T>
void Linked_List<T>::Erase(Iterator it)
{
    // A B C, B is provided by user = it
    // A C
    if (it == Begin())
    {
        Pop_Front();
        return;
    }
    if (it == End() || it == Iterator(Tail))
    {
        Pop_Back();
        return;
    }
    it.iter->Prev->Next = it.iter->Next; // A -> C
    it.iter->Next->Prev = it.iter->Prev; // C -> A
    delete it.iter;
}

template <typename T>
void Linked_List<T>::Remove(T val)
{
    for (auto iter = Begin(); iter != End(); iter++)
    {
        if (*iter == val)
        {
            if (iter == Begin())
            {
                Pop_Front();
            }
            else
            {
                auto temp = iter;
                temp--;
                Erase(iter);
                iter = temp;
            }
        }
    }
}

/// @brief 搜尋 LinkedList 中的資料
/// @param  特定資料
/// @return 回傳搜尋到的第一個特定資料迭代器
template <typename T>
typename Linked_List<T>::Iterator Find(Linked_List<T> list, const T val)
{
    auto current = list.Begin();
    while (current != list.End())
    {
        if (*current == val)
            break;
        current++;
    }
    return current; // Not found.
}

#endif // LINKED_LIST_H_INCLUDED
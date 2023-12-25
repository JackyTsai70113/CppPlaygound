#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T Data;
    Node *Next;
};

template <typename T>
class Queue
{
private:
    // First -> Second -> ... -> Rear

    // 刪除端的資料
    Node<T> *First;
    // 新增端的資料
    Node<T> *Rear;
    // 長度
    int Len;

public:
    Queue();
    // 回傳第一個被刪除的資料
    T Front();
    // 回傳最後一個被刪除的資料
    T Back();
    // 回傳佇列是否為空
    bool Empty();
    // 回傳佇列大小
    int Size();
    // 從尾端新增一筆資料
    void Push(T);
    // 從頭部刪除一筆資料
    void Pop();
    // 印出佇列的內容
    void Print_Queue();
};

template <typename T>
inline Queue<T>::Queue()
{
    First = Rear = nullptr;
    Len = 0;
}

template <typename T>
inline T Queue<T>::Front()
{
    if (Empty())
    {
        cout << "This queue is empty!" << endl;
        return 0;
    }
    return First->Data;
}

template <typename T>
inline T Queue<T>::Back()
{
    if (Empty())
    {
        cout << "This queue is empty!" << endl;
        return 0;
    }
    return Rear->Data;
}

template <typename T>
inline bool Queue<T>::Empty()
{
    return Rear == nullptr;
}

template <typename T>
inline int Queue<T>::Size()
{
    return Len;
}

template <typename T>
inline void Queue<T>::Push(T data)
{
    auto newNode = new Node<T>{data, nullptr};
    if (Empty())
    {
        First = Rear = newNode;
    }
    else
    {
        Rear->Next = newNode;
        Rear = Rear->Next;
    }
    Len++;
}

template <typename T>
inline void Queue<T>::Pop()
{
    if (Empty())
    {
        cout << "This queue is empty!" << endl;
        return;
    }
    if (Len == 1)
    {
        First = Rear = nullptr;
        Len = 0;
        return;
    }
    auto result = First;
    First = First->Next;

    Len--;
}

template <typename T>
inline void Queue<T>::Print_Queue()
{
    if (Empty())
    {
        cout << "This queue is empty!" << endl;
        return;
    }
    auto cur = First;
    cout << "Data: ";
    while (cur != nullptr)
    {
        cout << cur->Data << " ";
        cur = cur->Next;
    }
    cout << endl;
}

#endif // QUEUE_H_INCLUDED
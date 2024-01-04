#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
struct Node
{
    int index;
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
class Binary_Tree
{
private:
public:
    // 根節點
    Node<T> *root;
    // 建構式
    Binary_Tree();
    // 印出特定節點
    void Print(Node<T>);
    // 新增資料
    bool Insert(int index, T data);
    // 搜尋資料
    Node<T> *Search(int index);
    // 刪除資料
    bool Delete(int);
    // 尋訪: 前序中序後序
};

template <typename T>
Binary_Tree<T>::Binary_Tree()
{
    root = nullptr;
}

template <typename T>
void Binary_Tree<T>::Print(Node<T> node)
{
    cout << "Index: " << node.index << ", Data: " << node.data << endl;
}

template <typename T>
bool Binary_Tree<T>::Insert(int index, T data)
{
    Node<T> *newNode = new Node<T>{index, data, nullptr, nullptr};
    if (root == nullptr)
    {
        root = newNode;
        return true;
    }
    Node<T> *cur = root;
    while (true)
    {
        if (cur->index == index)
            return false;
        if (index < cur->index)
        {
            if (cur->left == nullptr)
            {
                cur->left = newNode;
                return true;
            }
            cur = cur->left;
        }
        else
        {
            if (cur->right == nullptr)
            {
                cur->right = newNode;
                return true;
            }
            cur = cur->right;
        }
    }
}

template <typename T>
Node<T> *Binary_Tree<T>::Search(int targetIndex)
{
    Node<T> *cur = root;
    while (cur != nullptr)
    {
        if (cur->index == targetIndex)
            return cur;
        if (cur->index > targetIndex)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return nullptr;
}

template <typename T>
bool Binary_Tree<T>::Delete(int)
{
    return false;
}

#endif // BINARY_TREE_H_INCLUDED
#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include <iostream>
#include <queue>

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
    Binary_Tree(T* datas, int size);
    // 前序尋訪
    void PreOrder(Node<T> *);
    // 中序尋訪
    void InOrder(Node<T> *);
    // 後序尋訪
    void PostOrder(Node<T> *);
    // level order 尋訪
    void LevelOrder(Node<T> *);
};

template <typename T>
Binary_Tree<T>::Binary_Tree(T*datas, int size)
{
    if(datas == nullptr){
        root = nullptr;
        return;
    }
    root = new Node<T>{0, datas[0], nullptr, nullptr};
    queue<Node<T> *> q;
    q.push(root);
    while(!q.empty()){
        Node<T>* node = q.front();
        q.pop();
        auto index = node->index;
        if(2 * index + 1 < size && datas[2 * index + 1] != 0){
            node->left = new Node<T>{2 * index + 1, datas[2 * index + 1], nullptr, nullptr};
            q.push(node->left);
        }
        if(2 * index + 2 < size && datas[2 * index + 2] != 0){
            node->right = new Node<T>{2 * index + 2, datas[2 * index + 2], nullptr, nullptr};
            q.push(node->right);
        }
    }
}

template <typename T>
void Binary_Tree<T>::PreOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    cout << node->data << ", ";
    if (node->left != nullptr)
    {
        PreOrder(node->left);
    }
    if (node->right != nullptr)
    {
        PreOrder(node->right);
    }
}

template <typename T>
void Binary_Tree<T>::InOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    if (node->left != nullptr)
    {
        InOrder(node->left);
    }
    cout << node->data << ", ";
    if (node->right != nullptr)
    {
        InOrder(node->right);
    }
}

template <typename T>
void Binary_Tree<T>::PostOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    if (node->left != nullptr)
    {
        PostOrder(node->left);
    }
    if (node->right != nullptr)
    {
        PostOrder(node->right);
    }
    cout << node->data << ", ";
}

template <typename T>
void Binary_Tree<T>::LevelOrder(Node<T> *node)
{
    if (node == nullptr)
        return;
    queue<Node<T> *> q;
    q.push(node);
    while (!q.empty())
    {
        for (int i = q.size(); i > 0; i--)
        {
            Node<T> *n = q.front();
            q.pop();
            cout << n->data << ", ";
            if (n->left != nullptr)
            {
                q.push(n->left);
            }
            if (n->right != nullptr)
            {
                q.push(n->right);
            }
        }
    }
}

#endif // BINARY_TREE_H_INCLUDED
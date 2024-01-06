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
    Node<T> *parent;
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
    // 前序尋訪
    void PreOrder(Node<T> *);
    // 中序尋訪
    void InOrder(Node<T> *);
    // 後序尋訪
    void PostOrder(Node<T> *);
    // level order 尋訪
    void LevelOrder(Node<T> *);
    // 最左節點
    Node<T> *Left_Most(Node<T> *);
    // 最右節點
    Node<T> *Right_Most(Node<T> *);
    // 前任，往左一個節點
    Node<T> *Predecessor(Node<T> *);
    // 接班人，往右一個節點
    Node<T> *Successor(Node<T> *);
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
                newNode->parent = cur;
                cur->left = newNode;
                return true;
            }
            cur = cur->left;
        }
        else
        {
            if (cur->right == nullptr)
            {
                newNode->parent = cur;
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
bool Binary_Tree<T>::Delete(int targetIndex)
{
    Node<T> *delete_node = Search(targetIndex);
    if (delete_node == nullptr)
    {
        return false;
    }

    // case 1. delete_node is a leaf node
    if (delete_node->left == nullptr && delete_node->right == nullptr)
    {
        if (delete_node == root)
        {
            root = nullptr;
        }
        if (delete_node == delete_node->parent->left)
        {
            cout << "left";
            delete_node->parent->left = nullptr;
        }
        else
        {
            cout << "right";
            delete_node->parent->right = nullptr;
        }
        delete delete_node;
    }
    // case 2. delete_node has 1 child node
    else if (delete_node->left == nullptr || delete_node->right == nullptr)
    {
        Node<T> *child = delete_node->left != nullptr ? delete_node->left : delete_node->right;
        if (delete_node == root)
        {
            root = child;
        }
        if (delete_node == delete_node->parent->left)
        {
            delete_node->parent->left = child;
        }
        else
        {
            delete_node->parent->right = child;
        }
        delete delete_node;
    }
    // case 3. delete_node has 2 child node
    else if (delete_node->left != nullptr && delete_node->right != nullptr)
    {
        Node<T> *successor = Left_Most(delete_node->right);
        // successor must has 0 or 1 child
        T successorData = successor->data;
        int successorIndex = successor->index;
        Delete(successor->index);
        delete_node->data = successorData;
        delete_node->index = successorIndex;
    }
    return true;
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

template <typename T>
Node<T> *Binary_Tree<T>::Left_Most(Node<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    auto result = node;
    while (result->left != nullptr)
    {
        result = result->left;
    }
    return result;
}

template <typename T>
Node<T> *Binary_Tree<T>::Right_Most(Node<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    auto result = node;
    while (result->right != nullptr)
    {
        result = result->right;
    }
    return result;
}

template <typename T>
Node<T> *Binary_Tree<T>::Predecessor(Node<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->left != nullptr)
    {
        return Right_Most(node->left);
    }

    Node<T> *cur = node->parent;
    while (cur != nullptr && cur->right != node)
    {
        node = cur;
        cur = cur->parent;
    }
    return cur;
}

template <typename T>
Node<T> *Binary_Tree<T>::Successor(Node<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->right != nullptr)
    {
        return Left_Most(node->right);
    }
    Node<T> *cur = node->parent;
    while (cur != nullptr && cur->left != node)
    {
        node = cur;
        cur = cur->parent;
    }
    return cur;
}
#endif // BINARY_TREE_H_INCLUDED
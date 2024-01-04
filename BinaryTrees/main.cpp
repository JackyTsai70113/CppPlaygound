#include "Binary_Tree.h"
#include <iostream>

using namespace std;

int main()
{
    Binary_Tree<int> tree;
    tree.Insert(2, 3);
    tree.Insert(3, 6);
    tree.Insert(7, 8);
    tree.Print(*tree.root);
    tree.Print(*(tree.root->right));
    auto found = tree.Search(7);
    tree.Print(*found);
    return 0;
}

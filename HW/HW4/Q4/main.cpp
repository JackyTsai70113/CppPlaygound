#include "Binary_Tree.h"
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,0,0,7};
    Binary_Tree<int> tree(arr, 7);
    
    cout << "Pre-Order: ";
    tree.PreOrder(tree.root);
    cout << endl;

    cout << "In-Order: ";
    tree.InOrder(tree.root);
    cout << endl;

    cout << "Post-Order: ";
    tree.PostOrder(tree.root);
    cout << endl;

    cout << "Level-Order: ";
    tree.LevelOrder(tree.root);
    cout << endl;

    return 0;
}
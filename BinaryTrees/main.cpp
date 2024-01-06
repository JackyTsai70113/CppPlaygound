#include "Binary_Tree.h"
#include <iostream>

using namespace std;
void TestTraverse()
{
    Binary_Tree<int> tree;
    tree.Insert(58, 58);
    tree.Insert(24, 24);
    tree.Insert(97, 97);
    tree.Insert(12, 12);
    tree.Insert(49, 49);
    tree.Insert(82, 82);
    tree.Insert(55, 55);

    tree.Print(*tree.root);
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

    cout << "Left most of 58: " << tree.Left_Most(tree.Search(58))->index << endl;
    cout << "Right most of 58: " << tree.Right_Most(tree.Search(58))->index << endl;
    cout << "Predecessor of 58: " << tree.Predecessor(tree.Search(58))->index << endl;
    cout << "Successor of 58: " << tree.Successor(tree.Search(58))->index << endl;
    cout << "Predecessor of 82: " << tree.Predecessor(tree.Search(82))->index << endl;
    cout << "Successor of 55: " << tree.Successor(tree.Search(55))->index << endl;
}

void TestDelete()
{
    Binary_Tree<string> tree;
    tree.Insert(58, "A");
    tree.Insert(24, "B");
    tree.Insert(97, "C");
    tree.Insert(12, "D");
    tree.Insert(49, "E");
    tree.Insert(82, "F");
    tree.Insert(55, "G");

    tree.Delete(58);

    tree.Print(*tree.root);
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

    cout << "Left most of 24: " << tree.Left_Most(tree.Search(24))->index << endl;
    cout << "Right most of 24: " << tree.Right_Most(tree.Search(24))->index << endl;
    cout << "Successor of 55: " << tree.Successor(tree.Search(55))->index << endl;
    cout << "Predecessor of 82: " << tree.Predecessor(tree.Search(82))->index << endl;
}

void TestHw6()
{
    Binary_Tree<int> tree;
    tree.Insert(5, 7);
    tree.Insert(3, 5);
    tree.Insert(7, 8);
    tree.Insert(1, 4);
    tree.Insert(4, 3);
    tree.Insert(6, 9);
    tree.Insert(8, 1);
    tree.Insert(2, 2);

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
}

int main()
{
    TestTraverse();
    TestDelete();
    TestHw6();

    return 0;
}

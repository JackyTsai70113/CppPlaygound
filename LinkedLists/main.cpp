#include "Circular_Linked_List.h"
#include "Linked_List.h"
#include <iostream>

using namespace std;

void test_linked_list()
{
    Linked_List<int> List;
    List.Push_Front(1);
    List.Push_Front(2);
    List.Push_Front(3);
    List.Print_List();

    List.Pop_Front();
    List.Pop_Front();
    List.Print_List();

    List.Pop_Front();
    List.Print_List();

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Print_List();

    List.Pop_Back();
    List.Pop_Back();
    List.Print_List();

    List.Pop_Back();
    List.Pop_Back();
    List.Print_List();

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Push_Back(4);
    List.Push_Back(5);
    List.Push_Back(6);
    List.Push_Back(7);
    List.Push_Back(8);
    List.Push_Back(9);
    List.Push_Back(2);
    List.Push_Back(2);
    List.Print_List();
    List.Remove(2);
    List.Print_List();
    cout << "Search 1: " << List.Search_List(1) << endl;
    cout << "Search 3: " << List.Search_List(3) << endl;

    auto iter2 = Find(List, 7);

    // 3 4 5 6
    for (auto iter1 = Find(List, 3); iter1 != iter2; iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << endl;

    // 3 100 4 5 6
    cout << "Insert 100 at element 4: ";
    List.Insert(Find(List, 4), 100);
    for (auto iter1 = Find(List, 3); iter1 != iter2; iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << endl;

    // 3 100 5 6
    cout << "Erase 4: ";
    List.Erase(Find(List, 4));
    for (auto iter1 = Find(List, 3); iter1 != iter2; iter1++)
    {
        cout << *iter1 << " ";
    }
    cout << endl;

    // cout << "Search 2: " << *Find(List, 2) << endl;
    // cout << "Search 3: " << *Find(List, 3) << endl;
    cout << "Search 5: " << *Find(List, 5) << endl;
    // List.Erase(Find(List, 4));
    List.Print_List();

    for (auto iter = List.Begin(); iter != List.End(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    auto iter1 = List.Begin();
    Advance(iter1, 3);
    cout << *iter1 << endl;
    Advance(iter1, -2);
    cout << *iter1 << endl;
    iter1 = Find(List, 5);
    iter2 = Find(List, 8);
    cout << Distance(iter1, iter2) << endl;
    cout << endl;
    // 3
}

void test_circular_linked_list()
{
    Circular_Linked_List<int> clist;
    clist.Push_Back(1);
    clist.Push_Back(2);
    clist.Push_Back(3);
    clist.Push_Back(4);
    clist.Push_Back(5);
    clist.Push_Back(6);
    clist.Push_Back(7);
    clist.Push_Back(8);
    clist.Print_List();
    clist.Rotate(3);
    clist.Print_List();
}

void test_list(){
    
}
int main()
{
    test_linked_list();

    test_circular_linked_list();

    return 0;
}

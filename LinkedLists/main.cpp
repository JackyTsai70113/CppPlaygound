#include "Linked_List.h"
#include <iostream>

using namespace std;

int main()
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
    List.Print_List();
    cout << "Search 1: " << List.Search_List(1) << endl;
    cout << "Search 3: " << List.Search_List(3) << endl;
    // cout << "Search 2: " << *Find(List, 2) << endl;
    // cout << "Search 3: " << *Find(List, 3) << endl;
    cout << "Search 4: " << *Find(List, 3) << endl;
    // List.Erase(Find(List, 4));
    List.Print_List();
    return 0;
}
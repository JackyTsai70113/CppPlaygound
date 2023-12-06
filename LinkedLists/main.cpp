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
    cout << List.Search_List(1) << endl;
    List.Pop_Front();
    List.Pop_Front();
    List.Print_List();
    List.Pop_Front();
    List.Print_List();
    cout << List.Search_List(1) << endl;

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Print_List();
    cout << List.Search_List(1) << endl;
    List.Pop_Back();
    List.Print_List();
    List.Pop_Back();
    List.Print_List();
    List.Pop_Back();
    List.Print_List();
    List.Pop_Back();
    List.Print_List();

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Print_List();
    List.Clear();
    List.Print_List();

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Print_List();
    List.Reverse();
    List.Print_List();
    return 0;
}
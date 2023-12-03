#include "Linked_List.h"
#include <iostream>

using namespace std;

int main()
{
    Linked_List<int> List;
    List.Print_List();
    cout << List.Search_List(1);
    return 0;
}
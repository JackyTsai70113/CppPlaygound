#include "Vector.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Vector<int> v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(2);
    v.Push_Back(2);
    v.Push_Back(6);
    v.Push_Back(2);

    for (int i = 0; i < v.Size(); i++)
        cout << v[i] << " ";
    cout << endl;

    cout << "after remove 2" << endl;
    Remove(v, 2);
    for (int i = 0; i < v.Size(); i++)
        cout << v[i] << " ";
    cout << endl;

    Vector<int>::Iterator iter2 = Find(v, 2);
    cout << "find 2: " << (iter2 - v.Begin()) << endl;

    cout << "find 9: ";
    iter2 = Find(v, 9);
    if (iter2 != v.End())
    {
        cout << *iter2 << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }

    // v.Erase(iter + 2);
    // for (int i = 0; i < v.Size(); i++)
    //     cout << v[i] << " ";
    // cout << endl;

    // v.Erase(iter + 2, iter + 4);
    // for (int i = 0; i < v.Size(); i++)
    //     cout << v[i] << " ";
    // cout << endl;

    // v.Clear();
    // cout << v.Size() << endl;
    // for (int i = 0; i < v.Size(); i++)
    //     cout << v[i] << " ";
    // cout << endl;
    return 0;
}
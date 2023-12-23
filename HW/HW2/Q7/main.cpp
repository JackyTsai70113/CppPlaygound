#include "Circular_Linked_List.h"
#include <iostream>

using namespace std;

Node<int> *PassBomb(Circular_Linked_List<int> &clist, Node<int> *bomber, int pass)
{
    for (int i = 1; i < pass; ++i)
    {
        bomber = bomber->Next;
    }
    bomber->Prev->Next = bomber->Next;
    bomber->Next->Prev = bomber->Prev;
    bomber = bomber->Next;
    return bomber;
}

int Play(Circular_Linked_List<int> clist, int m, int k)
{
    auto bomber = clist.Head_Node();
    for (int i = 0; i < k; i++)
    {
        bomber = PassBomb(clist, bomber, m);
    }
    return bomber->Data;
}

int main()
{
    int N;
    cin >> N;
    int M = 0;
    cin >> M;
    int K = 0;
    cin >> K;
    Circular_Linked_List<int> clist;
    for (int i = 1; i <= N; ++i)
    {
        clist.Push_Back(i);
    }
    cout << Play(clist, M, K) << endl;
    return 0;
}
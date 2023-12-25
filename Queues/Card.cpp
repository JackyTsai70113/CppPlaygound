#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter N: ";
    int n;
    cin >> n;

    Queue<int> cards;
    for (int i = 1; i <= n; ++i)
    {
        cards.Push(i);
    }
    cards.Print_Queue();

    int card;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Now, discard card #" << cards.Front() << endl;
        cards.Pop();
        auto card = cards.Front();
        cout << "Now, put the card #" << card << " to the bottom." << endl;
        cards.Push(card);
        cards.Pop();
        cards.Print_Queue();
    }
    cout << "The last, remainingcard is:" << cards.Front() << endl;

    return 0;
}

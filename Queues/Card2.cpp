#include <deque>
#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter N: ";
    int n;
    cin >> n;

    deque<int> cards;
    for (int i = 1; i <= n; ++i)
    {
        cards.push_back(i);
    }
    //cards.Print_Queue();

    int card;
    for (int i = 0; i < n - 1; i++)
    {
        // cout << "Now, discard card #" << cards.Front() << endl;
        cards.pop_front();
        auto card = cards.front();
        // cout << "Now, put the card #" << card << " to the bottom." << endl;
        cards.push_back(card);
        cards.pop_front();
        // cards.Print_Queue();
    }
    cout << "The last, remainingcard is:" << cards.front() << endl;

    return 0;
}

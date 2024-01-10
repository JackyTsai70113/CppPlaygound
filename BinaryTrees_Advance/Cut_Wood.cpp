#include <iostream>
#include <set>
#include <vector>

using namespace std;

int cutCount, len, positions[200000 + 10], position, idx;
long long int res = 0;
set<int> cut;

// https://zerojudge.tw/ShowProblem?problemid=f607
int main()
{
    cin >> cutCount >> len;
    for (int i = 0; i < cutCount; i++)
    {
        cin >> position >> idx;
        positions[idx - 1] = position;
    }
    cut.insert(0);
    cut.insert(len);
    for (int i = 0; i < cutCount; i++)
    {
        auto r = cut.upper_bound(positions[i]);
        auto l = r;
        l--;
        cut.insert(positions[i]);
        res += *r - *l;
    }
    cout << res;

    return 0;
}

/*
3 7
2 2
3 1
5 3
14

3 8
2 3
6 1
5 2
19
*/

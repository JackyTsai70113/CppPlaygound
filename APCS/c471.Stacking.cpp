#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first * b.second < a.second * b.first;
}

// https://zerojudge.tw/ShowProblem?problemid=c471
int main()
{
    long long int sum = 0, res = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> objects;
    objects.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> objects[i].first; // 重量
    }

    for (int i = 0; i < n; i++)
    {
        cin >> objects[i].second; // 次數
    }
    sort(objects.begin(), objects.end(), compare);
    for (int i = 0; i < n; i++)
    {
        res += sum * objects[i].second;
        sum += objects[i].first;
    }
    cout << res << endl;
    return 0;
}
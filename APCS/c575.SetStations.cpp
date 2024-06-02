#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> positions;

int AtLeast(int diameter)
{
    int cover = positions[0] + diameter;
    int res = 1;
    for (int i = 1; i < positions.size(); i++)
    {
        if (cover < positions[i])
        {
            res++;
            cover = positions[i] + diameter;
        }
    }
    return res;
}

int BinarySearch()
{
    int l = 1, r = positions.back() - positions.front();
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (AtLeast(m) <= K)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    positions.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> positions.at(i);
    }
    sort(positions.begin(), positions.end());
    cout << BinarySearch();

    return 0;
}

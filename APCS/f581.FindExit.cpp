#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<int> rooms;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    rooms.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> rooms.at(i);
    }
    vector<int> presum(M, 0);
    for (int i = 0; i < M; i++)
    {
        presum[i] = rooms[i];
        if (i > 0)
            presum[i] += presum[i - 1];
    }
    int mission, last = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> mission;
        if (last != -1)
            mission += presum[last];
        if (mission > presum.back())
            mission -= presum.back();
        last = lower_bound(presum.begin(), presum.end(), mission) - presum.begin();
    }

    cout << (last + 1) % M;

    return 0;
}

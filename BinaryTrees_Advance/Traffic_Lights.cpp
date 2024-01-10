#include <iostream>
#include <set>

using namespace std;

int main()
{
    // 取消綁定
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int len, lightCount;
    cin >> len >> lightCount;
    set<int> lights{0, len};
    multiset<int> distance{len};
    for (int i = 0; i < lightCount; i++)
    {
        int position;
        cin >> position;
        auto r = lights.upper_bound(position);
        auto l = r;
        l--;
        distance.erase(distance.find(*r - *l));
        distance.insert(*r - position);
        distance.insert(position - *l);
        lights.insert(position);
        cout << *(--distance.end()) << " ";
    }

    return 0;
}

/*
8 3
3 6 2
5 3 3
*/
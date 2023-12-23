#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Operate(int n, int dir, vector<vector<int>> v)
{
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int x = n / 2, y = n / 2, i = 0;
    string res = "";
    while (x >= 0 && y >= 0 && x < n && y < n)
    {
        for (int j = 0; j < i / 2 + 1; ++j)
        {
            res += to_string(v[x][y]);
            x += dirs[dir][0];
            y += dirs[dir][1];
        }

        i++;
        dir = (dir + 1) % 4;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int dir = 0;
    cin >> dir;
    vector<vector<int>> vv;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        vv.push_back(v);
    }
    auto actual = Operate(n, dir, vv);
    cout << actual << endl;
    return 0;
}
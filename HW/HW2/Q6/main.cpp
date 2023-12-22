#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n = 5;
    int dir = 0;
    vector<vector<int>> v{
        {3, 4, 2, 1, 4},
        {4, 2, 3, 8, 9},
        {2, 1, 9, 5, 6},
        {4, 2, 3, 7, 8},
        {1, 2, 6, 4, 3},
    };

    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int x = n / 2, y = n / 2, i = 0;
    string res = "";
    while (x >= 0 && y >= 0 && x < n && y < n)
    {
        cout << "before " << i << " " << (i / 2 + 1) << " " << x << " " << y << endl;
        for (int j = 0; j < i / 2 + 1; ++j)
        {
            cout << x << " " << y << endl;
            res += to_string(v[x][y]);
            x += dirs[dir][0];
            y += dirs[dir][1];
        }

        i++;
        dir = (dir + 1) % 4;
    }
    cout << res << endl;
    cout << "9123857324243421496834621";
    return 0;
}
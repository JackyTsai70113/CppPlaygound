#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Flip(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            swap(v[i][j], v[v.size() - i - 1][j]);
        }
    }
}

vector<vector<int>> Rotate(const vector<vector<int>> &v)
{
    vector<vector<int>> res;
    for (int i = 0; i < v[0].size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < v.size(); j++)
        {
            temp.push_back(v[j][v[0].size() - i - 1]);
        }
        res.push_back(temp);
    }
    return res;
}

vector<vector<int>> Operate(vector<vector<int>> &vv, const vector<int> &ops)
{
    auto res = vv;
    for (int i = ops.size() - 1; i >= 0; i--)
    {
        if (ops[i] == 0)
        {
            res = Rotate(res);
        }
        else
        {
            Flip(res);
        }
    }
    return res;
}

int main()
{
    int R;
    cin >> R;
    int C = 0;
    cin >> C;
    int M = 0;
    cin >> M;
    vector<vector<int>> vv;
    for (int i = 0; i < R; i++)
    {
        vector<int> v;
        for (int j = 0; j < C; j++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        vv.push_back(v);
    }
    vector<int> ops;
    for (int j = 0; j < M; j++)
    {
        int num;
        cin >> num;
        ops.push_back(num);
    }
    auto actual = Operate(vv, ops);
    int RR = actual.size(), CC = actual[0].size();
    cout << RR << " " << CC << endl;
    for (int i = 0; i < RR; ++i)
    {
        for (int j = 0; j < CC; ++j)
        {
            cout << actual[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n, k, sum = 0;
vector<long long int> pre_torque, suf_torque;
vector<int> nums;
int Cut(int k, int l, int r)
{
    if (r - l < 2 || k == 0)
        return 0;

    long prefix = 0;
    pre_torque[l] = 0;
    for (int i = l + 1; i <= r; ++i)
    {
        prefix += nums[i - 1];
        pre_torque[i] = prefix + pre_torque[i - 1];
    }

    long suffix = 0;
    suf_torque[r] = 0;
    for (int i = r - 1; i >= l; --i)
    {
        suffix += nums[i + 1];
        suf_torque[i] = suffix + suf_torque[i + 1];
    }

    int cut_point = -1;
    long long int min_torque = LONG_MAX;
    for (int i = l + 1; i < r; ++i)
    {
        long long int torque = abs(pre_torque[i] - suf_torque[i]);
        if (min_torque > torque)
        {
            cut_point = i;
            min_torque = torque;
        }
    }
    return nums[cut_point] + Cut(k - 1, l, cut_point - 1) + Cut(k - 1, cut_point + 1, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    pre_torque.resize(n);
    suf_torque.resize(n);
    cout << Cut(k, 0, n - 1) << endl;

    return 0;
}

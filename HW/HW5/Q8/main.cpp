#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        bool flg = 0;
        for (int i = 0; i < n; i++)
        {
            a = max(a, nums[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != a)
            {
                b = max(b, nums[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != a && nums[i] != b)
            {
                c = max(c, nums[i]);
                flg = 1;
            }
        }
        if (flg)
        {
            return c;
        }
        else
        {
            return a;
        }
    }
};

int main()
{
    vector<int> v{2, 2, 3, 1};
    Solution solution;
    auto num = solution.thirdMax(v);
    cout << num << endl;
}
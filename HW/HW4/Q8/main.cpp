#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return {};
        if (nums[0] > 0)
            return {};
        vector<vector<int>> res;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                break;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int temp = -1 * (nums[i] + nums[j]);
                if (map.count(temp) && map[temp] > j)
                {
                    res.push_back({nums[i], nums[j], temp});
                }
                j = map[nums[j]];
            }
            i = map[nums[i]];
        }
        return res;
    }
};

int main()
{
    vector<int> v{-1, 0, 1, 2, -1, -4};
    Solution solution;
    auto vv = solution.threeSum(v);
    for (int i = 0; i < vv.size(); i++)
    {
        for (auto it = vv[i].begin(); it != vv[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
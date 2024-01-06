#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(target - nums[i]))
                return {i, map[target - nums[i]]};
            map[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main()
{
    vector<int> v = {2, 7, 11, 15};
    Solution solution;
    auto v2 = solution.twoSum(v, 9);
    for (auto it = v2.begin(); it != v2.end(); it++)
        cout << *it << " ";
}
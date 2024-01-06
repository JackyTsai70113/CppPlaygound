#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        unordered_map<int, int> buckets;
        for (int i = 0; i < nums.size(); i++)
        {
            int bucket = nums[i] / (valueDiff + 1);
            if (nums[i] < 0)
                bucket--;
            if (buckets.count(bucket))
                return true;
            if (buckets.count(bucket - 1) && nums[i] - buckets[bucket - 1] <= valueDiff)
                return true;
            if (buckets.count(bucket + 1) && buckets[bucket + 1] - nums[i] <= valueDiff)
                return true;
            buckets[bucket] = nums[i];
            if (buckets.size() > indexDiff)
            {
                int key = nums[i - indexDiff] / (valueDiff + 1);
                if (nums[i - indexDiff] < 0)
                    key--;
                buckets.erase(key);
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> v1{1, 5, 9, 1, 5, 9};
    cout << solution.containsNearbyAlmostDuplicate(v1, 2, 3) << endl;
    vector<int> v2{1, 2, 3, 1};
    cout << solution.containsNearbyAlmostDuplicate(v2, 3, 0) << endl;
}
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto num : nums)
        {
            if (set.count(num))
            {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};

int main()
{
    vector<int> v{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    Solution solution;
    auto actual = solution.containsDuplicate(v);
    cout << actual << endl;
}
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        int left = 0, right = 0;
        deque<int> q;

        while (right < nums.size())
        {
            while (!q.empty() && nums[right] > nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(right);

            if (left > q.front())
            {
                q.pop_front();
            }

            if (right + 1 >= k)
            {
                res.push_back(nums[q.front()]);
                left++;
            }
            right++;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> v1{1, 3, -1, -3, 5, 3, 6, 7};
    auto v = solution.maxSlidingWindow(v1, 3);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v2{1};
    v = solution.maxSlidingWindow(v2, 1);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
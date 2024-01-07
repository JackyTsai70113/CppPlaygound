#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int n = candyType.size();
        unordered_set<int> s;
        for (auto x : candyType)
        {
            s.insert(x);
        }
        if (s.size() > n / 2)
        {
            return n / 2;
        }
        return s.size();
    }
};

int main()
{
    Solution solution;
    vector<int> v1{1, 1, 2, 3};
    auto a = solution.distributeCandies(v1);
    cout << a << " ";
}
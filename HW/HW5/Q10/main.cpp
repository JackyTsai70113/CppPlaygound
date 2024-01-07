#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

int main()
{
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    auto vv = solution.groupAnagrams(v);
    for (int i = 0; i < vv.size(); i++)
    {
        for (auto it = vv[i].begin(); it != vv[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
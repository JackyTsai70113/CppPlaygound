#include <vector>
#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> v;
        dfs(root, targetSum, v, res);
        return res;
    }

private:
    void dfs(TreeNode *root, int targetSum, vector<int> &v, vector<vector<int>> &res)
    {
        if (!root)
        {
            return;
        }
        v.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val)
        {
            res.push_back(v);
        }
        dfs(root->left, targetSum - root->val, v, res);
        dfs(root->right, targetSum - root->val, v, res);
        v.pop_back();
    }
};

int main()
{
    TreeNode t2(1);
    t2.left = new TreeNode{2};
    Solution solution;
    auto vv = solution.pathSum(&t2, 3);
    for (int i = 0; i < vv.size(); i++)
    {
        for (auto it = vv[i].begin(); it != vv[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
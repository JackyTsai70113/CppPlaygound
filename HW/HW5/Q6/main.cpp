#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
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
    bool isBalanced(TreeNode *root)
    {
        return solve(root) != -1;
    }

private:
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftHeight = solve(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = solve(root->right);
        if (rightHeight == -1)
            return -1;

        if (!(abs(leftHeight - rightHeight) <= 1))
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    TreeNode t(1);
    t.left = new TreeNode{2};
    t.left = new TreeNode{3};
    Solution solution;
    auto num = solution.isBalanced(&t);
    cout << num << endl;
}
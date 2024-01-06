#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

// binary tree node.
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main()
{
    TreeNode t1(1);
    TreeNode t2(1);
    TreeNode t3(2);
    Solution solution;
    cout << solution.isSameTree(&t1, &t2) << endl;
    cout << solution.isSameTree(&t2, &t3) << endl;
}
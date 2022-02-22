#include <iostream>
#include <vector>
#include <algorithm>
#include "Tree.h"
#include <queue>

using namespace std;

/*
// BFS Solution (Correct Answer but the sequence of the cycle will be wrong)
vector<int> boundaryOfBinaryTree(TreeNode* root)
{
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if ((!node->left && !node->right) || !i || i == sz - 1)
            {
                res.push_back(node->val);
            }
        }
    }
    return res;
}
*/

//DFS Solution
void dfs(TreeNode *node, bool l, bool r, vector<int>& res)
{
    if (!node) return;
    if (l) res.push_back(node->val);
    if (!l && !r && !node->left && !node->right)
    {
        res.push_back(node->val);
    }
    dfs(node->left, l, r && !node->right, res);
    dfs(node->right, l && !node->left, r, res);
    if (r) res.push_back(node->val);
}

vector<int> boundaryOfBinaryTree(TreeNode* root)
{
    vector<int> res;
    if (!root) return res;
    res.push_back(root->val);
    dfs(root->left, true, false, res);
    dfs(root->right, false, true, res);
    return res;
}

int main(void)
{

	return 0;
}
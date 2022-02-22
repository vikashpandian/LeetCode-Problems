#include <iostream>
#include <vector>
#include <algorithm>
#include "Tree.h"
#include <queue>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    if (!root) return {};
    vector<vector<int>> res;
    queue<TreeNode*> q({root});
    bool ltor = true;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            level[ltor ? i : sz - i - 1] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ltor = !ltor;
        res.push_back(move(level));
    }
    return res;
}

int main(void)
{

	return 0;
}
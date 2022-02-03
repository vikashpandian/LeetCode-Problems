#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include "Tree.h"

using namespace std;

/*
// O(M + N) Two Pass

void inorder(vector<int>& data, TreeNode* root)
{
    if (!root) return;
    inorder(data, root->left);
    data.push_back(root->val);
    inorder(data, root->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    vector<int> tree1, tree2;
    inorder(tree1, root1);
    inorder(tree2, root2);
    int m = tree1.size(), n = tree2.size();
    vector<int> res(m + n);
    tree1.push_back(INT_MAX);
    tree2.push_back(INT_MAX);
    for (int i = 0, x = 0, y = 0; i < res.size(); i++)
    {
        res[i] = (tree1[x] < tree2[y]) ? tree1[x++] : tree2[y++];
    }
    return res;
}
*/

void inorder(multiset<int>& data, TreeNode* root)
{
    if (!root) return;
    inorder(data, root->left);
    data.insert(root->val);
    inorder(data, root->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    multiset<int> data;
    inorder(data, root1);
    inorder(data, root2);
    return vector<int>(data.begin(), data.end());
}

int main(void)
{

	return 0;
}
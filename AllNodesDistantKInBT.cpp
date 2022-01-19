#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
# include "Tree.h"

using namespace std;

int find(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, int>& nodes)
{
	if (!root) return -1;
	if (root == target)
	{
		nodes[root] = 0;
		return 0;
	}
	int l = find(root->left, target, nodes);
	if (l >= 0)
	{
		nodes[root] = l + 1;
		return l + 1;
	}
	int r = find(root->right, target, nodes);
	if (r >= 0)
	{
		nodes[root] = r + 1;
		return r + 1;
	}
	return -1;
}

void dfs(TreeNode* root, int length, int k, unordered_map<TreeNode*, int>& nodes, vector<int>& result)
{
	if (!root) return;
	if (nodes.count(root)) length = nodes[root];
	if (length == k) result.push_back(root->val);
	dfs(root->left, length + 1, k, nodes, result);
	dfs(root->right, length + 1, k, nodes, result);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
	unordered_map<TreeNode*, int> nodes;
	vector<int> result;
	find(root, target, nodes);
	dfs(root, nodes[root], k, nodes, result);
	return result;
}

int main(void)
{

	return 0;
}
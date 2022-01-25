#include <iostream>
#include <vector>
#include <algorithm>
#include "Tree.h"
#include <queue>

using namespace std;

/*
//Inorder Traversal Approach (Doesn't Work)
TreeNode* node = nullptr;
int from_lvl, lvl;

bool inorder_find(TreeNode* root, TreeNode* u, TreeNode* prev, int prev_lvl, int cur_lvl)
{
	if (!root) return false;
	if (root == u)
	{
		node = prev;
		from_lvl = prev_lvl;
		lvl = cur_lvl;
		return true;
	}
	return (inorder_find(root->left, u, root, cur_lvl, cur_lvl + 1) ||
			inorder_find(root->right, u, prev, prev_lvl, cur_lvl + 1));
}

TreeNode* find_right_node(TreeNode* root, int to_lvl, int cur_lvl)
{
	if (!root || cur_lvl > to_lvl) return nullptr;
	if (cur_lvl == to_lvl)
	{
		return root;
	}
	TreeNode* left = find_right_node(root->left, to_lvl, cur_lvl + 1);
	if (left) return left;
	return find_right_node(root->right, to_lvl, cur_lvl + 1);
}

TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u)
{
	if (inorder_find(root, u, nullptr, 0, 0))
	{
		return find_right_node(node->right, lvl, from_lvl + 1);
	}
	return nullptr;
}
*/

//BFS Solution
TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u)
{
	queue<TreeNode*> nodes({ root });
	while (!nodes.empty())
	{
		int sz = nodes.size();
		while (sz--)
		{
			TreeNode* node = nodes.front();
			nodes.pop();
			if (node == u)
			{
				if (sz) return nodes.front();
				else return nullptr;
			}
			if (node->left) nodes.push(node->left);
			if (node->right) nodes.push(node->right);
		}
	}
	return nullptr;
}

int main(void)
{
	queue<TreeNode*> nodes({ new TreeNode() });
	return 0;
}
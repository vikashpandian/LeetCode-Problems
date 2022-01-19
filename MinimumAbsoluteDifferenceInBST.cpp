#include <iostream>
#include "tree.h"

using namespace std;

int inorder(TreeNode* root, long& minimum, long prev) {
	if (!root) return prev;
	prev = inorder(root->left, minimum, prev);
	minimum = min((minimum), root->val - prev);
	prev = inorder(root->right, minimum, root->val);
	return prev;
}

int getMinimumDifference(TreeNode* root) {
	long mini = INT_MAX;
	long prev = INT_MIN;
	inorder(root, mini, prev);
	return mini;
}

int main(void) {
	TreeNode* root = new TreeNode(236, new TreeNode(104, nullptr, new TreeNode(227)), new TreeNode(701, nullptr, new TreeNode(911)));
	cout << getMinimumDifference(root);
	return 0;
}
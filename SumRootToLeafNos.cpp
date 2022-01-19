#include <iostream>
#include "tree.h"

using namespace std;

void sumNumbers(TreeNode* node, int& sum, int curVal) {
	curVal = curVal * 10 + node->val;
	if (!node->left && !node->right) sum += curVal;
	if (node->left) sumNumbers(node->left, sum, curVal);
	if (node->right) sumNumbers(node->right, sum, curVal);
}

int sumNumbers(TreeNode* root) {
	int sum = 0;
	sumNumbers(root, sum, 0);
	return sum;
}

int main(void) {
	TreeNode* tree = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
	cout << sumNumbers(tree);
	return 0;
}
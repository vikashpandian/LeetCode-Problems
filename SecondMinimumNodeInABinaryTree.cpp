#include <iostream>
#include "Tree.h"

using namespace std;

void inorderSecondMin(TreeNode* node, long& m1, long& m2) {
	if (!node) return;
	inorderSecondMin(node->left, m1, m2);
	int val = node->val;
	if (val < m2) {
		if (val > m1) m2 = val;
		else if (val < m1) m2 = m1, m1 = val;
	}
	inorderSecondMin(node->right, m1, m2);
}

int findSecondMinimumValue(TreeNode* root) {
	if (!root || (!root->left && !root->right)) return -1;
	long m1 = root->val, m2 = LONG_MAX;
	inorderSecondMin(root, m1, m2);
	return m2 != LONG_MAX ? m2 : -1;
}

int main(void) {
	cout << findSecondMinimumValue(sampTree);
	return 0;
}
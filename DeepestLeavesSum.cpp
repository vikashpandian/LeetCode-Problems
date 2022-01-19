#include <iostream>
#include "tree.h"

using namespace std;

void deepestLeavesSum(TreeNode* n, int& sum, int& maxHt, int lvl) {
	if (!n->left && !n->right) {
		if (lvl == maxHt) sum += n->val;
		else if (lvl > maxHt) maxHt = lvl, sum = n->val;
		return;
	}
	if (n->left) deepestLeavesSum(n->left, sum, maxHt, lvl + 1);
	if (n->right) deepestLeavesSum(n->right, sum, maxHt, lvl + 1);
}

int deepestLeavesSum(TreeNode* root) {
	int sum = 0, maxHt = 0;
	deepestLeavesSum(root, sum, maxHt, 1);
	return sum;
}

int main(void) {
	TreeNode* tree = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
	cout << tree->toPrintable();
	cout << "\n" << deepestLeavesSum(tree) << endl;
	return 0;
}
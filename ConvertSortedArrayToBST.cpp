#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

TreeNode* createBST(vector<int>& nums, int l, int r) {
	if (l == r) return new TreeNode(nums.at(l));
	TreeNode* root = nullptr;
	if (l < r) {
		int mid = (l + r) / 2;
		root = new TreeNode(nums.at(mid));
		root->left = createBST(nums, l, mid - 1);
		root->right = createBST(nums, mid + 1, r);
	}
	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return createBST(nums, 0, nums.size() - 1);
}

int main(void) {
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };
	TreeNode* out = sortedArrayToBST(nums);
	cout << out->toPrintable();
	return 0;
}
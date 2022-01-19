#include <iostream>
#include <vector>
#include <unordered_map>
#include "Tree.h"

using namespace std;

void findFq(TreeNode* node, vector<int>& res, int& maxFq, int& cnt, int& prev, bool populate) {
	if (!node) return;
	findFq(node->left, res, maxFq, cnt, prev, populate);
	++(cnt *= (node->val == prev));
	maxFq = max(maxFq, cnt);
	prev = node->val;
	if (populate && maxFq == cnt) res.push_back(node->val);
	findFq(node->right, res, maxFq, cnt, prev, populate);
}

vector<int> findMode(TreeNode* root) {
	vector<int> res;
	if (root) {
		int maxFq = 0, cnt = 0, prev;
		findFq(root, res, maxFq, cnt, prev, false);
		cnt = 0;
		findFq(root, res, maxFq, cnt, prev, true);
	}
	return res;
}

int main(void) {
	auto out = findMode(sampTree);
	for (auto i : out) cout << i << "\t";
	return 0;
}
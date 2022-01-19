#include <iostream>
#include <vector>
#include <queue>
#include "Tree.h"

using namespace std;

/* 
BFS Solution
Not memory efficient
*/
vector<int> largestValues(TreeNode* root) {
	vector<int> res;
	if (root) {
		queue<TreeNode*> q({ root });
		while (!q.empty()) {
			int sz = q.size(), maxVal = INT_MIN;
			while (sz--) {
				TreeNode* cur = q.front();
				maxVal = max(maxVal, cur->val);
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				q.pop();
			}
			res.push_back(maxVal);
		}
	}
	return res;
}

//TODO : DFS Solution

int main(void) {
	cout << sampTree->toPrintable();
	auto out = largestValues(sampTree);
	for (auto i : out) cout << i << "\t";
	return 0;
}
#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

void inorder(TreeNode* root, vector<int>& out) {
    if (root) {
        inorder(root->left, out);
        out.push_back(root->val);
        inorder(root->right, out);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> out;
    inorder(root, out);
    return out;
}

int main(void) {
    TreeNode* tree = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    cout << tree->toPrintable();
    vector<int> out = inorderTraversal(tree);
    for (int i : out) cout << i << "\t\t";
	return 0;
}
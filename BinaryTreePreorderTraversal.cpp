#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

void preorderTraversal(TreeNode* node, vector<int>& vals) {
    if (!node) return;
    vals.push_back(node->val);
    preorderTraversal(node->left, vals);
    preorderTraversal(node->right, vals);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vals;
    preorderTraversal(root, vals);
    return vals;
}

int main(void) {
    TreeNode* tree = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    cout << tree->toPrintable();
    vector<int> out = preorderTraversal(tree);
    for (int i : out) cout << i << "\t\t";
    return 0;
}
#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/*
bool isValidBST(TreeNode* root, long prev, bool less) {
    if (!root) return true;
    int val = root->val;
    if ((less && val >= prev) || (!less && val <= prev)) return false;
    return isValidBST(root->left, val, true) && isValidBST(root->right, val, false);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, INT_MAX, true);
}
*/

/*
bool isValidBST(TreeNode* node, long& prev) {
    if (!node) return true;
    return isValidBST(node->left, prev) && (node->val > prev) && isValidBST(node->right, prev = node->val);
}

bool isValidBST(TreeNode* root) {
    long prev = LONG_MIN;
    return isValidBST(root, prev);
}
*/

bool isValidBST(TreeNode* node, int*& prev) {
    if (!node) return true;
    return isValidBST(node->left, prev) && (!prev || node->val > *prev) && isValidBST(node->right, prev = &(node->val));
}

bool isValidBST(TreeNode* root) {
    int* prev = nullptr;
    return isValidBST(root, prev);
}

int main(void) {
    TreeNode* p = new TreeNode(9, new TreeNode(1), new TreeNode(11));
    TreeNode* q = new TreeNode(1, nullptr, new TreeNode(3));
    cout << isValidBST(p);
    return 0;
}
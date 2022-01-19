#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/*
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if ((!p || !q) || (p->val != q->val)) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
    return ((!p && !q) || ((p && q) && (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))));
}

int main(void) {
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, nullptr, new TreeNode(3));
    cout << isSameTree(p, q);
    return 0;
}
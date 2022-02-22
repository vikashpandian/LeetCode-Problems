#include <iostream>
#include <vector>
#include <algorithm>
#include "Tree.h"

using namespace std;

int maxDepth(TreeNode* root)
{
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(void)
{

	return 0;
}
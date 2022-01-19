#include <iostream>
#include <vector>
#include <string>
#include <set>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if (!root->left && !root->right)
            return true;
        TreeNode* temp1 = root->left;
        TreeNode* temp2 = root->right;
        while (temp1->left && temp2->right && temp1->left->val == temp2->right->val) {

        }
        return false;
    }
};

int main() {

	return 0;
}

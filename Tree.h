#pragma once
#include <string>

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    void printBST(std::string& buffer, std::string prefix, std::string childrenPrefix) {
        buffer.append(prefix);
        buffer += std::to_string(val);
        buffer += '\n';
        if(!right && left) left->printBST(buffer, childrenPrefix + "|-- ", childrenPrefix + "    ");
        else {
            if (left) left->printBST(buffer, childrenPrefix + "|-- ", childrenPrefix + "|   ");
            if (right) right->printBST(buffer, childrenPrefix + "|-- ", childrenPrefix + "    ");
        }
    }
    std::string toPrintable() {
        std::string buffer;
        printBST(buffer, "", "");
        return buffer;
    }
};


TreeNode* sampTree = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
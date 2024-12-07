/*
BST means left node value should always be less than root and right side value is always more than root
      10
     /  \
    5    15
   / \   / \
  2   8 12  20

Left node : [INT MIN , root val] : for node 5 it must be ranged bw INT MIN and 10
i.e: min < left node < root,   INT_MIN < 5< 10

Reft node : [root val, INT MIN  : for node 15 it must be ranged bw 10 and INT MAX
i.e: root < right node < INT_MAX,   10 < 15< INT_MAX


*/





#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(TreeNode* node, int min, int max) {
    if (node == nullptr)
        return true;

    // Check if the node's value falls within the valid range
    if (node->val <= min || node->val >= max)
        return false;

    // Recursively check the left and right subtrees
    return isBSTUtil(node->left, min, node->val) &&
           isBSTUtil(node->right, node->val, max);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(17);

    if (isBST(root)) {
        cout << "The tree is a Binary Search Tree" << endl;
    } else {
        cout << "The tree is not a Binary Search Tree" << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

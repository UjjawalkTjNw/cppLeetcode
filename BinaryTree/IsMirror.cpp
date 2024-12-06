/*
Mirror does not mean symmetry
In mirrorwe check if left of root and right of root has same value or not
But in symmetry left and right side value does not matter:

eg: Mirror:
         1
       /   \
      2     2
     / \   / \
    3   4 4   3


eg:Symmetry:
         1
       /   \
      2     10
     / \   / \
    3   6 8   15

eg: not symmerty:
         1
       /   \
      2     10
     / \      \
    3   6     15

     
*/


#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isMirror(root->left, root->right);
}

int main() {
    // Create a symmetric binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Check if the tree is symmetric
    if (isSymmetric(root)) {
        cout << "The tree is symmetric" << endl;
    } else {
        cout << "The tree is not symmetric" << endl;
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

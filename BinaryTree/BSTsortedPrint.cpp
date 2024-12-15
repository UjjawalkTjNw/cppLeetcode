#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    // Traverse left subtree
    inorderTraversal(root->left);

    // Visit root node
    cout << root->val << " ";

    // Traverse right subtree
    inorderTraversal(root->right);
}

int main() {
    // Creating the BST example
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << "BST elements in sorted order: ";
    inorderTraversal(root);
    cout << endl;

    // Free allocated memory (optional in this simple example)
    // In a real application, use smart pointers or proper memory management
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}

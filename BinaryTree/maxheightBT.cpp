#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// Helper function to create a new node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    // Create a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6

    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    cout << "The maximum height of the binary tree is: " << maxDepth(root) << endl;

    return 0;
}

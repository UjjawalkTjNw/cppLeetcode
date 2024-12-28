/*
         1
     /       \
    2        3          
  /   \      /  \
4     5      6   7

The above tree after invert will become like this:

        1
     /       \
    3        2          
  /   \      /  \
 7    6      5   4

*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        
        // Swap the left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

// Helper function to print the tree in-order
void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    cout << "Original tree in-order: ";
    printInOrder(root);
    cout << endl;
    
    Solution sol;
    root = sol.invertTree(root);
    
    cout << "Inverted tree in-order: ";
    printInOrder(root);
    cout << endl;
    
    return 0;
}

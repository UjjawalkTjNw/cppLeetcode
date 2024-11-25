#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int sum = 0;
    //check if root has left child
    //if yes then check if left child is leaf[left right = NULL]
    //or left child exist and not leaf: find leaf
    eg1:     3      [Left of root is leaf itself: if condn]
          /   \
        9     20
            /   \
          15     7

    eg2:      3      [Left of root is not leaf : else cond]
          /    \
        9         20
       / \        /   \
     12   13     15     7


    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(NULL);
    root->left->right = new TreeNode(NULL);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int sum = sumOfLeftLeaves(root);
    std::cout << "Sum of left leaves: " << sum << std::endl;

    return 0;
}
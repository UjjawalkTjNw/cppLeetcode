/*
Description:
Given a tree:
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \      \
  7    2      1


  We have been given a sum (Lets say 22); and we have to find if deepest leaf sum is equal to this given sum or not

  Note: For solving this we use DFS 
  Approach: if the deepest leaves sum is 22 then diff bw given sum and deepest leaf sum is 0
  i.e: we keep decrementing given sum till deepest leaf nodes. If given sum become zero then "Yes"
  the path has sum as given sum

*/



#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;

    sum -= root->val;

    // Check if we reached a leaf node and the remaining sum is 0
    if (root->left == NULL && root->right == NULL) return sum == 0;

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main() {
    // Creating the tree from the example
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    int sum = 22;
    bool result = hasPathSum(root, sum);
    std::cout << "Has Path Sum (" << sum << "): " << (result ? "Yes" : "No") << std::endl;

    return 0;
}

/*DRY RUN
Initial Call: hasPathSum(root, 22), where root is the node with value 5.

Node 5:

sum -= root->val → sum = 22 - 5 = 17

root->left is not NULL and root->right is not NULL, so we continue.

Recursively call hasPathSum(root->left, 17) and hasPathSum(root->right, 17).

Node 4 (left child of 5):

sum -= root->val → sum = 17 - 4 = 13

root->left is not NULL and root->right is NULL, so we continue.

Recursively call hasPathSum(root->left, 13).

Node 11 (left child of 4):

sum -= root->val → sum = 13 - 11 = 2

root->left is not NULL and root->right is not NULL, so we continue.

Recursively call hasPathSum(root->left, 2) and hasPathSum(root->right, 2).

Node 7 (left child of 11):

sum -= root->val → sum = 2 - 7 = -5

root->left is NULL and root->right is NULL (leaf node), so we check if sum == 0.

sum is not 0, return false.

Node 2 (right child of 11):

sum -= root->val → sum = 2 - 2 = 0

root->left is NULL and root->right is NULL (leaf node), so we check if sum == 0.

sum == 0, return true.

Since we have found a path with the sum of 22, the function returns true.


*/

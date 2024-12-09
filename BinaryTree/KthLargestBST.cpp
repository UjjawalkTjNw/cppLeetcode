/*
Tree:
       5
      / \
     3   6
    / \
   2   4
  /
 1

We have to find third largest.
Approach: find inorder traversal recursively it will give u 3rd largest (kth largest)

For abve example:
   1 2 3 4 5 6 : this we can get from inorder traversal 

*/


#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorderTraversal(root, k, count, result);
        return result;
    }

    void inorderTraversal(TreeNode* node, int k, int& count, int& result) {
        if (node == NULL || count >= k) {
            return;
        }
        inorderTraversal(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorderTraversal(node->right, k, count, result);
    }
};

// Helper function to insert a new node in the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    Solution solution;
    int k = 3;
    cout << "The " << k << "rd smallest element in the BST is: " << solution.kthSmallest(root, k) << endl;

    return 0;
}

/*
Dry run:


Let's say k = 3 (we want the 3rd smallest element).

First call: inorderTraversal(5, 3, 0, -1)

Current node is 5.

Calls inorderTraversal(3, 3, 0, -1) (left subtree).

Second call: inorderTraversal(3, 3, 0, -1)

Current node is 3.

Calls inorderTraversal(2, 3, 0, -1) (left subtree).

Third call: inorderTraversal(2, 3, 0, -1)

Current node is 2.

Calls inorderTraversal(1, 3, 0, -1) (left subtree).

Fourth call: inorderTraversal(1, 3, 0, -1)

Current node is 1.

Calls inorderTraversal(NULL, 3, 0, -1) (left subtree). Since node is NULL, returns immediately.

Increments count to 1.

count != k, so moves on.

Calls inorderTraversal(NULL, 3, 1, -1) (right subtree). Since node is NULL, returns immediately.

Return to third call: Back to node 2.

Increments count to 2.

count != k, so moves on.

Calls inorderTraversal(NULL, 3, 2, -1) (right subtree). Since node is NULL, returns immediately.

Return to second call: Back to node 3.

Increments count to 3.

count == k, sets result = 3.

Returns immediately since we found the k-th smallest element.


*/

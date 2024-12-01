/*This is code for inorder traversal , similarly u can do for pre and post order also
preorder:
            v.push_back(root->val);
            helperFunc(root->left, v);
            helperFunc(root->right, v);
PostOrder:
            helperFunc(root->left, v);
            helperFunc(root->right, v);
            v.push_back(root->val);
           

*/
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    void helperFunc(TreeNode* root, vector<int>& v) { 
        if (root != NULL) {
            helperFunc(root->left, v);
            v.push_back(root->val);
            helperFunc(root->right, v);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        helperFunc(root, v);
        return v;
    }
};

int main() {
    // Create the binary tree for input: root = [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Instantiate Solution and call inorderTraversal
    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}

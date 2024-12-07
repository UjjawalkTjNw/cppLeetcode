/*
Level order traversal is done using bfs not dfs
We go level by level of graph/tree i.e: level 0 ->level 1 ->level 2 and so on

eg:
        1
       / \
      2   3
     / \   \
    4   5   6

    Op: [1,2,3,4,5,6]


*/


#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    // Creating the tree from the example
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    std::cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    return 0;
}

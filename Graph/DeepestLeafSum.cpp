#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int deepestLeavesSum(TreeNode* root) {
    if (root == NULL) return 0;

    std::queue<TreeNode*> q;
    q.push(root);
    int sum = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        sum = 0;  // Reset sum for the current level [write this step little late ;) ]

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return sum;  // Sum of the deepest leaves
}

int main() {
    // Creating the tree from the example
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int sum = deepestLeavesSum(root);
    std::cout << "Deepest Leaves Sum: " << sum << std::endl;

    return 0;
}

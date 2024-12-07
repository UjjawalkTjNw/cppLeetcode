/*
Calculate the sum at each level of tree /graph

eg:
        1
       / \
      2   3
     / \   \
    4   5   6

Level 0: 1 sum =1
Level 1: 2,3 sum =5
Level 2: 4,5,6 sum =15

Op = [1, 5 , 15]

*/


#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> levelSums(TreeNode* root) {
    std::vector<int> sums;
    if (root == NULL) return sums; //return an empty vector if root is null

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int levelSum = 0;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            levelSum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        sums.push_back(levelSum);
    }
    return sums;
}

int main() {
    // Creating the tree from the example
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    std::vector<int> sums = levelSums(root);
    std::cout << "Level Sums: ";
    for (int sum : sums) {
        std::cout << sum << " ";
    }

    return 0;
}

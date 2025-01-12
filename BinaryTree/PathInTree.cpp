
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* node, string path, vector<string>& paths) {
    if (node) {
        path += to_string(node->val);
        if (!node->left && !node->right) {  // if leaf node
            paths.push_back(path);
        } else {
            path += "->";
            dfs(node->left, path, paths);
            dfs(node->right, path, paths);
        }
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    dfs(root, "", paths);
    return paths;
}

int main() {
    // Constructing the tree [1,2,3,null,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> result = binaryTreePaths(root);
    for (const string& path : result) {
        cout << path << endl;
    }

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

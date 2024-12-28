
/*Tree 1 (Main Tree):**
```
      1
     / \
    2   3
   / \
  4   5
```

**Tree 2 (Subtree):**
```
    2
   / \
  4   5
```

*/


#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    //both trees Null then true
    if (root1 == NULL && root2 == NULL) return true;
    //one of tree is not null and other is null
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->val == root2->val &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

bool isSubtree(TreeNode* mainTree, TreeNode* subTree) {
    //Three cases:
        //case1: root null ,subroot not null then false;
        //case2: root not null, subroot null then true;
        //case3: both main and sub tree looks same
    if (subTree == NULL) return true;
    if (mainTree == NULL) return false;
    if (areIdentical(mainTree, subTree)) return true;
    return isSubtree(mainTree->left, subTree) || isSubtree(mainTree->right, subTree);
}

int main() {
    // Creating the main tree
    TreeNode* mainTree = new TreeNode(1);
    mainTree->left = new TreeNode(2);
    mainTree->right = new TreeNode(3);
    mainTree->left->left = new TreeNode(4);
    mainTree->left->right = new TreeNode(5);

    // Creating the subtree
    TreeNode* subTree = new TreeNode(2);
    subTree->left = new TreeNode(4);
    subTree->right = new TreeNode(5);

    if (isSubtree(mainTree, subTree)) {
        cout << "Tree 2 is a subtree of Tree 1" << endl;
    } else {
        cout << "Tree 2 is NOT a subtree of Tree 1" << endl;
    }

    return 0;
}

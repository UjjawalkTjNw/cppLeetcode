/*
Balanced BST means left and right subtree height  difference is atmost 1
*/

#include <iostream>
#include <vector>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

// Helper function to build a balanced BST from a sorted array
//we can build balaced bst using sorted array, because in sorted array we can get middle elemet
// and make a tree using its left and right and that will always be balanced
TreeNode* sortedArrayToBST(const std::vector<int>& arr, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to perform in-order traversal of the tree
//Inorder gives the ascending order of tree
//so it validates that sorted array is used to create the BST and it is balanced

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = sortedArrayToBST(arr, 0, arr.size() - 1);

    std::cout << "In-order Traversal of the Balanced BST: ";
    inorderTraversal(root);

    return 0;
}
/*
Dry run:
Initial Call
Function Call: sortedArrayToBST(arr, 0, 6)

Start: 0, End: 6

Mid: 3 (mid = 0 + (6 - 0) / 2)

Create TreeNode with value 4

Left Subtree:

Function Call: sortedArrayToBST(arr, 0, 2)

Start: 0, End: 2

Mid: 1 (mid = 0 + (2 - 0) / 2)

Create TreeNode with value 2

Right Subtree:

Function Call: sortedArrayToBST(arr, 4, 6)

Start: 4, End: 6

Mid: 5 (mid = 4 + (6 - 4) / 2)

Create TreeNode with value 6

Second Level of Recursion
Left Subtree of Left Subtree:

Function Call: sortedArrayToBST(arr, 0, 0)

Start: 0, End: 0

Mid: 0 (mid = 0 + (0 - 0) / 2)

Create TreeNode with value 1

Function Call: sortedArrayToBST(arr, 0, -1) → Returns nullptr

Function Call: sortedArrayToBST(arr, 1, 0) → Returns nullptr

Right Subtree of Left Subtree:

Function Call: sortedArrayToBST(arr, 2, 2)

Start: 2, End: 2

Mid: 2 (mid = 2 + (2 - 2) / 2)

Create TreeNode with value 3

Function Call: sortedArrayToBST(arr, 2, 1) → Returns nullptr

Function Call: sortedArrayToBST(arr, 3, 2) → Returns nullptr

Left Subtree of Right Subtree:

Function Call: sortedArrayToBST(arr, 4, 4)

Start: 4, End: 4

Mid: 4 (mid = 4 + (4 - 4) / 2)

Create TreeNode with value 5

Function Call: sortedArrayToBST(arr, 4, 3) → Returns nullptr

Function Call: sortedArrayToBST(arr, 5, 4) → Returns nullptr

Right Subtree of Right Subtree:

Function Call: sortedArrayToBST(arr, 6, 6)

Start: 6, End: 6

Mid: 6 (mid = 6 + (6 - 6) / 2)

Create TreeNode with value 7

Function Call: sortedArrayToBST(arr, 6, 5) → Returns nullptr

Function Call: sortedArrayToBST(arr, 7, 6) → Returns nullptr

Summary of Function Calls and Array Transformations
sortedArrayToBST(arr, 0, 6) → Mid: 3, Create Node: 4

sortedArrayToBST(arr, 0, 2) → Mid: 1, Create Node: 2

sortedArrayToBST(arr, 4, 6) → Mid: 5, Create Node: 6

sortedArrayToBST(arr, 0, 0) → Mid: 0, Create Node: 1

sortedArrayToBST(arr, 2, 2) → Mid: 2, Create Node: 3

sortedArrayToBST(arr, 4, 4) → Mid: 4, Create Node: 5

sortedArrayToBST(arr, 6, 6) → Mid: 6, Create Node: 7


*/
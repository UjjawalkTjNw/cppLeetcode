/*
eg:

    1
   / \
  2   5
 / \   \
3   4   6


When flattened to a linked list, it should look like this:


1 - 2 - 3 - 4 - 5 - 6


*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if (!root) return;

    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printList(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);
    printList(root);

    return 0;
}


/*
Dry run:
Sure! Let's dry run the code step by step to understand how it works.

### Initial Tree Structure


    1
   / \
  2   5
 / \   \
3   4   6


### Step-by-Step Execution

1. **Start at the root (1):**
   - `curr` points to `1`.
   - `1` has a left child (`2`).

2. **Find the rightmost node of the left subtree of `1`:**
   - `pre` starts at `2`.
   - Move `pre` to `4` (rightmost node of the left subtree).

3. **Rewire the connections:**
   - `4`'s right child becomes `5` (original right child of `1`).
   - `1`'s right child becomes `2` (left child of `1`).
   - `1`'s left child is set to `NULL`.

   The tree now looks like this:

   
   1
    \
     2
    / \
   3   4
        \
         5
          \
           6
   

4. **Move to the next node (`2`):**
   - `curr` points to `2`.
   - `2` has a left child (`3`).

5. **Find the rightmost node of the left subtree of `2`:**
   - `pre` starts at `3`.
   - `3` has no right child, so `pre` remains `3`.

6. **Rewire the connections:**
   - `3`'s right child becomes `4` (original right child of `2`).
   - `2`'s right child becomes `3` (left child of `2`).
   - `2`'s left child is set to `NULL`.

   The tree now looks like this:

   
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
   

7. **Move to the next node (`3`):**
   - `curr` points to `3`.
   - `3` has no left child, so move to the next node (`4`).

8. **Move to the next node (`4`):**
   - `curr` points to `4`.
   - `4` has no left child, so move to the next node (`5`).

9. **Move to the next node (`5`):**
   - `curr` points to `5`.
   - `5` has no left child, so move to the next node (`6`).

10. **Move to the next node (`6`):**
    - `curr` points to `6`.
    - `6` has no left child and no right child, so the process ends.

### Final Flattened List


1 - 2 - 3 - 4 - 5 - 6

*/



/*
Consider the following singly linked list:

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL


The corresponding BST would look like this:

       4
     /   \
    2     6
   / \   / \
  1   3 5   7

*/

#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the middle element of the linked list
ListNode* findMiddle(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr; // Split the list into two halves
    }

    return slow;
}

// Function to convert sorted linked list to BST
TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* mid = findMiddle(head);

    TreeNode* root = new TreeNode(mid->data);

    if (head == mid) {
        return root; // Base case when there is only one element in the linked list
    }

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create a sorted linked list: 1->2->3->4->5->6->7->NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    TreeNode* root = sortedListToBST(head);

    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}





/*DRY RUN


1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL


### Step-by-Step Dry Run

1. **First Call: `sortedListToBST(head)`**
   - **Input**: `head` points to `1`
   - **Find Middle**: `mid` is `4`
   - **Create Root**: `root` is `TreeNode(4)`
   - **Recursive Calls**:
     - `root->left = sortedListToBST(head)` (left subtree)
     - `root->right = sortedListToBST(mid->next)` (right subtree)

2. **Second Call: `sortedListToBST(head)` for Left Subtree**
   - **Input**: `head` points to `1`
   - **Find Middle**: `mid` is `2`
   - **Create Root**: `root` is `TreeNode(2)`
   - **Recursive Calls**:
     - `root->left = sortedListToBST(head)` (left subtree)
     - `root->right = sortedListToBST(mid->next)` (right subtree)

3. **Third Call: `sortedListToBST(head)` for Left Subtree of `2`**
   - **Input**: `head` points to `1`
   - **Find Middle**: `mid` is `1`
   - **Create Root**: `root` is `TreeNode(1)`
   - **Base Case**: `head == mid`, so return `root`

4. **Fourth Call: `sortedListToBST(mid->next)` for Right Subtree of `2`**
   - **Input**: `head` points to `3`
   - **Find Middle**: `mid` is `3`
   - **Create Root**: `root` is `TreeNode(3)`
   - **Base Case**: `head == mid`, so return `root`

5. **Fifth Call: `sortedListToBST(mid->next)` for Right Subtree of `4`**
   - **Input**: `head` points to `5`
   - **Find Middle**: `mid` is `6`
   - **Create Root**: `root` is `TreeNode(6)`
   - **Recursive Calls**:
     - `root->left = sortedListToBST(head)` (left subtree)
     - `root->right = sortedListToBST(mid->next)` (right subtree)

6. **Sixth Call: `sortedListToBST(head)` for Left Subtree of `6`**
   - **Input**: `head` points to `5`
   - **Find Middle**: `mid` is `5`
   - **Create Root**: `root` is `TreeNode(5)`
   - **Base Case**: `head == mid`, so return `root`

7. **Seventh Call: `sortedListToBST(mid->next)` for Right Subtree of `6`**
   - **Input**: `head` points to `7`
   - **Find Middle**: `mid` is `7`
   - **Create Root**: `root` is `TreeNode(7)`
   - **Base Case**: `head == mid`, so return `root`

### Final BST Structure

       4
     /   \
    2     6
   / \   / \
  1   3 5   7
*/


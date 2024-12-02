/*
example tree:
      10
     /  \
    5    15
example tree 2:
      10
     /  \
    5    15
   / \   / \
  2   7 12  20



*/


#include <iostream>

struct node {
    int value = 0;
    node *left = nullptr, *right = nullptr, *parent = nullptr;
    node(int i): value(i) {};
};

node* findMin(node* root) {
    if (!root) return nullptr;
    while (root->left) {
        root = root->left;
    }
    return root;
}

node* findNext(node* cur) {
    if (!cur) return nullptr;
    
    if (cur->right) {
        return findMin(cur->right);
    } else {
        node* parent = cur->parent;
        while (parent && cur == parent->right) {
            cur = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

void traversal(node* root) {
    node* current = findMin(root);
    while (current) {
        std::cout << current->value << " ";
        current = findNext(current);
    }
}

int main() {
    // Create a sample BST
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->parent = root;
    root->right->parent = root;

    // Add more nodes as needed...
    
    // Perform traversal
    traversal(root);
    
    // Cleanup (delete allocated nodes)
    // Make sure to delete all nodes to avoid memory leaks

    return 0;
}


/*Dry run:
Scenario 1: cur = 2
Step 1: cur = 2

Step 2: 2 has no right child.

Step 3: Move up to its parent 5 (left child check).

Next Node: 5

Scenario 2: cur = 5
Step 1: cur = 5

Step 2: 5 has a right child 7.

Step 3: Use findMin to get the leftmost node in the right subtree of 5. findMin(7) returns 7.

Next Node: 7

Scenario 3: cur = 7
Step 1: cur = 7

Step 2: 7 has no right child.

Step 3: Move up to its parent 5. cur (7) is the right child of 5, so continue moving up to 10 (left child check).

Next Node: 10

Scenario 4: cur = 10
Step 1: cur = 10

Step 2: 10 has a right child 15.

Step 3: Use findMin to get the leftmost node in the right subtree of 10. findMin(15) returns 12.

Next Node: 12

Scenario 5: cur = 12
Step 1: cur = 12

Step 2: 12 has no right child.

Step 3: Move up to its parent 15 (left child check).

Next Node: 15

Scenario 6: cur = 15
Step 1: cur = 15

Step 2: 15 has a right child 20.

Step 3: Use findMin to get the leftmost node in the right subtree of 15. findMin(20) returns 20.

Next Node: 20

Scenario 7: cur = 20
Step 1: cur = 20

Step 2: 20 has no right child.

Step 3: Move up to its parent 15, and then to 10 (right child of parent check).

Next Node: nullptr (end of traversal).

Summary
Leftmost node: The smallest node, found using findMin.

findNext function: Helps find the next node in an inorder traversal using parent pointers.

*/

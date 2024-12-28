/*

        1
       / \
      2   3
     / \   \
    4   5   6
   /
  7


The left view of this binary tree is: `1, 2, 4, 7`.

*/

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to print the left view of the binary tree
void leftView(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 1; i <= n; i++) {
            TreeNode* temp = q.front();
            q.pop();

            // Print the leftmost element at the level
            if (i == 1) {
                cout << temp->val << " ";
            }

            // Add left node to queue
            if (temp->left != NULL) {
                q.push(temp->left);
            }

            // Add right node to queue
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    // Creating the example binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    // Printing the left view of the binary tree
    cout << "Left view of the binary tree is: ";
    leftView(root);

    return 0;
}



/*Dry run


initially 1 goes to queue , so q has 1
1.
now q is not empty
n = 1
so for loop runs q time :
temp =1 
q pooped so q has nothing now

yes, i == 1 so print : 1

q. push left and right becos they r not null, so q  has now 2,3
for loop end.

so at end of for loop queue have  2,3

2.
again q not empty, 
n = 2

for loop runs 2 time:
first time ->
temp = 2
2 is popped from queue, 
yes i == 1 now so print 2 , so we have 1 , 2 in left view now

push 4 ,5 in queue becos they r left and right of 2, so queue has 3 4 5


for loop running second time:
temp = 3
3 is popped of queue
no i not equal 3 so donot print
3 has right only so push right , so queue has 4,5 6 now
for loop ends


so at end of for loop queue have 4,5,6

so again repeat same steps


at the end we will have 1 2 4 7 as answer

*/



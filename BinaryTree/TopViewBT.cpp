        1
       /  \
      2   3
    /   \    \
   4   5    6

ans: [4 2 1 3 6]
explanation: 1 will be 0 , left is -2 -1 right is +1 , +2
i.e: 4 is at -2 , 2 is at -1 , 1 is at 0 , 3 is at +1; 6 is at +2 


#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to print the top view of the binary tree
void topView(Node* root) {
    if (root == nullptr) return;

    // Map to store the top view nodes
    map<int, int> topViewMap;
    // Queue to store nodes along with their horizontal distance
    queue<pair<Node*, int>> q;  // here int is for horizontal distance i.e -2 -1 0 1 2 them we call as horizontal distance

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        Node* node = p.first;
        int hd = p.second;
        q.pop();

        // If this horizontal distance is not already in the map
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }

        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Print the top view
    for (auto it : topViewMap) {
        cout << it.second << " ";
    }
    cout << endl;
}

// Helper function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

int main() {
    // Creating the example tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << "Top view of the binary tree is: ";
    topView(root);

    return 0;
}

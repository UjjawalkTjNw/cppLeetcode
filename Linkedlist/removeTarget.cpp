#include <bits/stdc++.h>
using namespace std;

//#include <iostream>
//using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete the node given only the pointer to it
void deleteNode(ListNode* node) {
    if (node == NULL || node->next == NULL) {
        return; // if the node is null or it's the last node
    }
    
    ListNode* temp = node->next;
    node->val = temp->val;  // Copy data from next node to this node
    node->next = temp->next; // Link to the node after the next node
    delete temp; // Delete the next node
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(6);
    ListNode* seventh = new ListNode(7);
    ListNode* eighth = new ListNode(8);
    ListNode* ninth = new ListNode(9);
    ListNode* tenth = new ListNode(10);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    
    // Deleting the fourth node (which has the value 4)
    deleteNode(fourth);

    // Print the linked list after deletion
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    // Clean up memory
    current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

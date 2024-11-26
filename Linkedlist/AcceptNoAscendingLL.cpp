#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a node in ascending order
void insertInAscendingOrder(ListNode*& head, int number) {
    ListNode* newNode = new ListNode(number);  // function accept LL and created a node

    // Case 1: Insertion into an empty list 
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Case 2: Insertion at the beginning of the list
    // consider a case if number is 1 so new node created 1 and existing LL is like 2->3->5
    //so in such case 1 should be at beggining of LL . so LL become 1->2->3-5

    if (number <= head->val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 3 and 4: Insertion in the middle or at the end of the list
    //This is more generic case to insert at any position based on number
    // consider number is 4 and so the new node created is 4 and existing LL is 2->3->5
    //so LL should traversed and this 4 should be entered after 3 , so LL become 2->3->4->5
    ListNode* current = head;
    while (current->next != nullptr && current->next->val < number) {
        current = current->next;
    }

    // Insert the new node after the current node
    newNode->next = current->next;
    current->next = newNode;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode* head = nullptr;

    // Insert numbers into the list
    insertInAscendingOrder(head, 5);
    insertInAscendingOrder(head, 3);
    insertInAscendingOrder(head, 8);
    insertInAscendingOrder(head, 1);
    insertInAscendingOrder(head, 6);

    // Print the linked list
    printList(head);

    return 0;
}

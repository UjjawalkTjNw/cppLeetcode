/*Sure! Let's start with an example of how a circular linked list (CLL) looks and how it differs from a singly linked list (SLL).

### Circular Linked List (CLL)
In a circular linked list, the last node points back to the first node, forming a circle. This means there is no `NULL` at the end of the list.

Example:

head -> 1 -> 2 -> 3 -> 4 -> head


### Singly Linked List (SLL)
In a singly linked list, the last node points to `NULL`, indicating the end of the list.

Example:

head -> 1 -> 2 -> 3 -> 4 -> NULL

//NOTE: THIS Problem is similar to remove target where we mimic the next node and remove that
*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to delete a node in a circular linked list
void deleteNode(Node* node) {
    if (node == nullptr) return;

    // If the node is the only node in the list
    if (node->next == node) {
        delete node;
        node = nullptr;
        return;
    }

    // Copy the data of the next node to the current node
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;

    // Delete the next node
    delete temp;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to create a new node
Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

int main() {
    // Create a circular linked list: 1->2->3->4->1
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head;

    cout << "Original List: ";
    printList(head);

    // Delete node 3
    deleteNode(head->next->next);

    cout << "List after deleting node 3: ";
    printList(head);

    return 0;
}

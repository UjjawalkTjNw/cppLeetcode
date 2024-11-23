#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to get nth node from end
Node* getNthFromEnd(Node* head, int n) {
    Node* first = head;
    Node* second = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == nullptr) return nullptr; // n is greater than the number of nodes
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // second pointer will be at the nth node from the end
    return second;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create the linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    cout << "Original List: ";
    printList(head);

    int n = 4;
    Node* nthNode = getNthFromEnd(head, n);
    if (nthNode != nullptr) {
        cout << "The " << n << "th node from the end is: " << nthNode->data << endl;
    } else {
        cout << "The list has fewer than " << n << " nodes." << endl;
    }

    return 0;
}

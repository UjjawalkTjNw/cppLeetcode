#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to insert a node at a given position
void insertAtPosition(Node* head, int position, int data) {
    if (position < 1) {
        std::cout << "Invalid position\n";
        return;
    }

    Node* newNode = createNode(data);
    Node* current = head;
    int count = 1;

    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        std::cout << "Position out of bounds\n";
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);

    // Insert a node at the end
    insertAtEnd(head, 7);

    // Insert a node at position 3
    insertAtPosition(head, 3, 4);

    printList(head); // Output: 1 3 4 5 7

    return 0;
}
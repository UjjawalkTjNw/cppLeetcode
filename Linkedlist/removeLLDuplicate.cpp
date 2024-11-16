#include <iostream>

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* runner = current; // better replace runner keyword with checker
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
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

// Function to create a linked list
Node* createLinkedList(int arr[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, n);

    std::cout << "Original Linked List: ";
    printList(head);

    removeDuplicates(head);

    std::cout << "Linked List after removing duplicates: ";
    printList(head);

    return 0;
}
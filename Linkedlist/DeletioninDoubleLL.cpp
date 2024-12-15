#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int val) {
        if (!head) return;
        
        Node* temp = head;
        
        // Find the node to be deleted
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        
        // If the node is not found
        if (!temp) return;
        
        // If the node to be deleted is the head node
        if (temp == head) {
            head = temp->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        
        // If the node to be deleted is not the head node
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    cout << "Original list: ";
    dll.printList();

    dll.deleteNode(3);

    cout << "List after deleting node with value 3: ";
    dll.printList();

    return 0;
}

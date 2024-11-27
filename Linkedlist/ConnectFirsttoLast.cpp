#include <iostream>

struct Node {
    char data;
    Node* next;
};

Node* createLinkedList(const char* str) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (const char* p = str; *p != '\0'; ++p) {
        Node* newNode = new Node;
        newNode->data = *p;
        newNode->next = nullptr;

        if (head == nullptr) {// initially LL is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
//Whole idea is to divide LL a->b->c->d->e->f->g->null into two halfs
//a->b->c->d->null   and e->f->g->null
//then reverse second half , after that start connecting

Node* reverseConnections(Node* head) {
    ////head == null checks if LL is empty
    //head->next == null checks if LL has only one element
    //in both cases just return 1
    if (head == nullptr || head->next == nullptr) {
        return head;
    } 

    // Find the middle node
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node* secondHalf = slow->next;
    slow->next = nullptr;
    Node* prev = nullptr;
    Node* current = secondHalf;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    secondHalf = prev;

    // Connect the ends //Revise this part one two time
    Node* firstHalf = head;
    while (firstHalf != nullptr && secondHalf != nullptr) {
        Node* firstNext = firstHalf->next;
        Node* secondNext = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = firstNext;

        firstHalf = firstNext;
        secondHalf = secondNext;
    }

    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    const char* str = "abcdefg";
    Node* head = createLinkedList(str);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    head = reverseConnections(head);

    std::cout << "Modified linked list: ";
    printLinkedList(head);

    return 0;
}
//Every character one node so n character n node so Space complexity  = O(n)
// head , next ,prev all pointers constant so dont take much space so O(1)
//Hence, overall SC = O(n)

//Iterate and find middle: O(n)
//reverse second half O(n/2)
//connecting then each element O(n)
// Therefore overall TC = O(n)
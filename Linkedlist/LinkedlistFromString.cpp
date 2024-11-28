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
#include <iostream>

struct ListNode {
    char data;
    ListNode* next;
    ListNode(char x) : data(x), next(nullptr) {}
};

// Function to check if the second list is a subsequence of the first list
bool isSubsequence(ListNode* head1, ListNode* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data == head2->data) {
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    return head2 == nullptr; // If we've matched the entire second list, return true
}

// Helper function to create a linked list from a string
ListNode* createLinkedList(const std::string& str) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (char ch : str) {
        ListNode* newNode = new ListNode(ch);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print the linked list (for debugging)
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create the original linked list: N -> E -> W -> D -> E -> L -> H -> I
    ListNode* list1 = createLinkedList("NEWDELHI");

    // Create the input linked list: N -> E -> W
    ListNode* list2 = createLinkedList("new");

    // Check if list2 is a subsequence of list1
    bool result = isSubsequence(list1, list2);

    std::cout << (result ? "The input linked list is a subsequence." : "The input linked list is not a subsequence.") << std::endl;

    return 0;
}


#include<bits/stdc++.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != NULL) {
            if (current->val == val) {
                prev->next = current->next;
                ListNode* temp = current;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Creating a linked list with the values {1, 2, 6, 3, 4, 5, 6}
    std::vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createList(values);

    std::cout << "Original list: ";
    printList(head);

    // Removing elements with value 6
    head = solution.removeElements(head, 6);

    std::cout << "List after removing elements with value 6: ";
    printList(head);

    return 0;
}

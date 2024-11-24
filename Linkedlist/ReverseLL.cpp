class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* nextN = NULL;
        while(current!=NULL){
            nextN = current->next;
            current->next = prev;
            prev = current;
            current = nextN;

        }
        //at the end prev will be at end of actual LL, so return prev
        return head = prev;
        
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next ==NULL) return head;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr && fastptr->next){
            slowptr= slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
        
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        //make two pointers and put them at head of LL
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
            
            if(fast==slow)
                return true;
        }
        return false ;
        
        
    }
};
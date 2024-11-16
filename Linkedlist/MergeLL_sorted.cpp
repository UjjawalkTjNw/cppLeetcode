class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //we have to return head 
        ListNode* head= new ListNode(0); // The 0 passed to the constructor means that the new node is initialized with the value 0.
        //In other words, head->val will be set to 0, and head->next will be set to nullptr when the ListNode constructor is called.
        //The 0 passed to the constructor means that the new node is initialized with the value 0.
        //In other words, head->val will be set to 0, and head->next will be set to nullptr when the ListNode constructor is called.
        ListNode* current = head ; 
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                current->next = list1 ;
                list1=list1->next;
            }
            else {
                current->next = list2;
                list2=list2->next;
            }
            //update current to next value
            current=current->next;
        }
        
        //Not necessarily list1 and list2 are of same size
        if(list1!=NULL)  current->next =list1; // i.e list1 remained and list 2 empty
        if(list2!=NULL)  current->next =list2; // i.e list2 remained and list 1 empty
        
        return head->next ;
    }
};
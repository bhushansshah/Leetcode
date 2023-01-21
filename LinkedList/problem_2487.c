 struct ListNode * makeChanges(struct ListNode *prev, struct ListNode *curr){
     if(!curr->next){
         return curr;
     }
     struct ListNode *head = makeChanges(curr, curr->next);
     if(curr->val < curr->next->val){
         if(prev)
            prev->next = curr->next;
     }
     else{
         head = curr;
     }
     return head;

 }
struct ListNode* removeNodes(struct ListNode* head){
    return makeChanges(NULL, head);
}

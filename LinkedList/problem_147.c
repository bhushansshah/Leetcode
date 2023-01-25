struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode *first = head;
    struct ListNode *before, *prev = head;
    struct ListNode *n = head->next;
    if(!head || !head->next)
        return head;
    while(n){
        first = head;
        before = NULL;
        while(first != n && first->val <= n->val){
            before = first;
            first = first->next;
        }
        if(first != n){
            if(before){
                prev->next = n->next;
                before->next = n;
                n->next = first;
            }
            else{
                prev->next = n->next;
                n->next = head;
                head = n;
            }
            n = prev->next;
        }
        else{
            prev = n;
            n = n->next;
        }
    }
    return head;
}

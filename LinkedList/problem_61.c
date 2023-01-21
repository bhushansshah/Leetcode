struct ListNode* rotateRight(struct ListNode* head, int k){
    int size = 1;
    struct ListNode *dup = head;
    struct ListNode *prev = NULL;
    if(!head || !head->next)
        return head;
    while(dup->next){
        size++;
        dup = dup->next;
    }
    k = k % size;
    if(!k)
        return head;
    dup->next = head;
    dup = head;
    for(int i = 0; i < size - k; i++){
        prev = dup;
        dup = dup->next;
    }
    prev->next = NULL;
    return dup;
}

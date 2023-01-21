struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *temp = head;
    if(!head || !head->next)
        return NULL;
    while(fast && fast->next){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    // while(temp->next != slow)
    //     temp = temp->next;
    // temp->next = slow->next;
    return head;
}

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode *front, *back;
    front = back = head;
    int temp, size = 0;
    while(front){
        front = front->next;
        size++;
    }
    front = head;
    for(int i = 0; i < k - 1; i++){
        front = front->next;
    }
    for(int i = 0; i < size - k; i++){
        back = back->next;
    }
    temp = front->val;
    front->val = back->val;
    back->val = temp;
    return head;
}

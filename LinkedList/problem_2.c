struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *dup = NULL;
    int c = 0, r;
    while(l1 && l2){
        r = (l1->val + l2->val + c) % 10;
        c = (l1->val + l2->val + c) / 10;
        if(!head){
            head = malloc(sizeof(struct ListNode));
            head->val = r;
            head->next = NULL;
            dup = head;
        }
        else{
            head->next = malloc(sizeof(struct ListNode));
            head = head->next;
            head->val = r;
            head->next = NULL;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        r = (l1->val + c) % 10;
        c = (l1->val + c) / 10;
        if(!head){
            head = malloc(sizeof(struct ListNode));
            head->val = r;
            head->next = NULL;
            dup = head;
        }
        else{
            head->next = malloc(sizeof(struct ListNode));
            head = head->next;
            head->val = r;
            head->next = NULL;
        }
        l1 = l1->next;
    }
    while(l2){
        r = (l2->val + c) % 10;
        c = (l2->val + c) / 10;
        if(!head){
            head = malloc(sizeof(struct ListNode));
            head->val = r;
            head->next = NULL;
            dup = head;
        }
        else{
            head->next = malloc(sizeof(struct ListNode));
            head = head->next;
            head->val = r;
            head->next = NULL;
        }
        l2 = l2->next;
    }
    if(c){
        head->next = malloc(sizeof(struct ListNode));
        head->next->val = c;
        head->next->next = NULL;
    }
    return dup;
}

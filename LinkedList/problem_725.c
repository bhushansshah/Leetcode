struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    struct ListNode *dup = head;
    int size = 0;
    int i = 0;
    int n;
    while(dup){
        size++;
        dup = dup->next;
    }
    struct ListNode **result = malloc(sizeof(struct ListNode *) * k);
    for(int i = 0; i < k; i++)
        result[i] = NULL;
    *returnSize = k;
    while(size){
        n = size / k;
        if(size % (k--))
            n++;
        size -= n;
        result[i++] = head;
        for(int j = 0; j < n - 1; j++)
            head = head->next;
        dup = head->next;
        head->next = NULL;
        head = dup;
    }
    return result;
}

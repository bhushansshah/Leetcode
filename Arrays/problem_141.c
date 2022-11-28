bool hasCycle(struct ListNode *head){
    // int flag = 0;
    // hashMap start;
    // hashMap* dup = &start;
    // start.p = head;
    // start.hashNext = NULL;
    // head = head->next;
    // while(head != NULL){
    //     dup = &start;
    //     while(dup != NULL){
    //         if(dup->p == head){
    //             flag == 1;
    //             break;
    //         }
    //         if(dup->hashNext == NULL){
    //             dup->hashNext = malloc(sizeof(hashMap) * 1);
    //             (dup->hashNext)->p = head;
    //             (dup->hashNext)->hashNext = NULL;
    //             break;    
    //         }
    //         dup = dup->hashNext;
    //     }
    //     if(flag){
    //         break;
    //     }
    //     head = head->next;
    // }
    // if(flag){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    struct ListNode* slow = head;
    if(!head || !head->next){
        return false;
    }
    struct ListNode* fast = head->next;
    while(slow != fast){
        if(fast == NULL || !fast->next || !fast->next->next){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

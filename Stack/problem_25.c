/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * recursive(struct ListNode *prev, struct ListNode *curr, int k, int len){
    if(!curr || (len < k)){
        return prev;
    }
    struct ListNode *last = prev;
    struct ListNode *temp;
    int i = 0;
    while((i < k - 1) && curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        i++;
    }
    if(!curr){
        last->next = NULL;
        return prev;
    }
    last->next = recursive(curr, curr->next, k, len - k);
    return prev;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *iter = head;
    int len = 0;
    if(k == 1 || !head || !head->next){
        return head;
    }
    while(iter){
        len++;
        iter = iter->next;
    }
    head = recursive(head, head->next, k, len); 
    return head;

}

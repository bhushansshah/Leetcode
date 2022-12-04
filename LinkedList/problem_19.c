/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 0;
    struct ListNode *dup = head;
    if(head->next == NULL){
        return NULL;
    }
    while(dup){
        len++;
        dup = dup->next;
    }
    if(n == len){
        return head->next;
    }
    dup = head;
    for(int i = 0; i < len - n - 1; i++){
        dup = dup->next;
    }
    dup->next = dup->next->next;
    return head;
}

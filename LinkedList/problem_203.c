/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* first = head;
    struct ListNode* second;
    while(first &&  first->val == val)
        first = first->next;
    head = first;
    if(first)
        second = first->next;
    while(second){
        if(second->val == val){
            first->next = second->next;
            second = first->next;
        }
        else{
            first = first->next;
            second = second->next;
        }
    }
    return head;
}

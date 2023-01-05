/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 void reverseKaro(struct ListNode *prev, struct ListNode *curr ,int count){
     if(!count){
         return;
     }
     struct ListNode *temp = curr->next;
     curr->next = prev;
     count--;
     reverseKaro(curr, temp, count);
 }
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left == right){
        return head;
    }
    struct ListNode *temp;
    struct ListNode *leftNode = head;
    struct ListNode *rightNode = head;
    for(int i = 0; i < left - 1; i++){
        if(i == left - 2){
            temp = leftNode;
        }
        leftNode = leftNode->next;
    }
    rightNode = leftNode;
    for(int i = 0; i < right - left; i++){
        rightNode = rightNode->next;
    }
    if(left != 1){
        temp->next = rightNode;
    }
    reverseKaro(rightNode->next, leftNode, right - left + 1);
    if(left != 1){
        return head;
    }
    else{
        return rightNode;
    }
}

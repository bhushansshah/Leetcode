/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* node){
    if(!node || !node->next || !node->next->next){
        return;
    }
    struct ListNode *dup = node;
    struct ListNode *fn = node;
    struct ListNode *sn = node->next;
    struct ListNode *ln = node;
    struct ListNode *temp;
    int len = 1;
    while(dup->next){
        len++;
        dup = dup->next;
    }
    ln = dup;
    int iter = len / 2;
    if(len % 2 == 0){
        iter--;
    }
    for(int i = 0; i < iter; i++){
        temp = node;
        for(int j = 0; j < len - 2; j++){
            temp = temp->next;
        }
        ln->next = fn->next;
        fn->next = ln;
        fn = sn;
        sn = sn->next;
        if(!sn)
            break;
        ln = temp;
        if(sn == ln)
            break;
    }
    ln->next = NULL;
}

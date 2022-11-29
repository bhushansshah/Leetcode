/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // struct ListNode* dupA = headA;
    // struct ListNode* dupB = headB;
    // int flag = 0;
    // if(headA == headB){
    //     return headA;
    // }
    // while(dupA->next){
    //     dupA = dupA->next;
    // }
    // while(dupB->next){
    //     dupB = dupB->next;
    // }
    // if(dupA != dupB){
    //     return NULL;
    // }
    // dupA = headA;
    // while(dupA){
    //     dupB = headB;
    //     while(dupB){
    //         if(dupB == dupA){
    //             flag = 1;
    //             break;
    //         }
    //         dupB = dupB->next;
    //     }
    //     if(flag){
    //         return dupA;
    //     }
    //     dupA = dupA->next;
    // }
    // return NULL;
    struct ListNode* dupA = headA;
    struct ListNode* dupB = headB;
    struct ListNode* result = NULL;
    while(dupA){
        dupA->val *= -1;
        dupA = dupA->next;
    }
    while(dupB){
        if(dupB->val < 0){
            result = dupB;
            break;
        }
        dupB = dupB->next;
    }
    dupA = headA;
    while(dupA){
        dupA->val *= -1;
        dupA = dupA->next;
    }
    return result;
}

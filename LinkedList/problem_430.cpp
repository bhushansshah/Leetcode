class Solution {
public:
    Node * flatList(Node *head){
        if(!head->child && !head->next)
            return head;
        Node *n = head->next;
        Node *last;
        if(head->child){
            last = flatList(head->child);
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;
            last->next = n;
            if(n)
                n->prev = last;
        }
        if(n)
            return flatList(n);
        while(head->next){
            head = head->next;
        }
        return head;
    }
    Node* flatten(Node* head) {
        if(!head)
            return head;
        flatList(head);
        return head;
    }
};

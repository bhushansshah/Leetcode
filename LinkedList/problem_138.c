struct Node* copyRandomList(struct Node* head)
{
    if (!head)
        return NULL;
    
    for (struct Node *i = head, *tmp; i; i = tmp->next)
    {
        tmp = malloc(sizeof(struct Node));
        tmp->val = i->val;
        tmp->next = i->next;
        tmp->random = i->random;
        i->next = tmp;
    }
    
    head = head->next;
    
    for (struct Node *i = head; ; i = i->next)
    {
        if (i->random)
            i->random = i->random->next;
        if (!i->next)
            break;
        i->next = i->next->next;
    }
    
    return head;
}

struct tnode *remove_c(struct tnode * head, char val)
{
    tnode_templ *temp = head;
    tnode_templ *temp2;
    while(temp->next != NULL) 
    {

        if(temp->next == NULL && temp->value != val) printf("Brak elementu w liscie!\n");
        else if(temp->prev == NULL && temp->value == val)
        {
            (temp->next)->prev = NULL;
            temp2 = temp->next;
            free(temp);
            

        }
        else if(temp->next == NULL && temp->value == val)
        {
            (temp->prev)->next = NULL;
            temp2 = temp->prev;
            free(temp);
            
        }
        else
        {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
            return head;
        }
        temp = temp->next; 
    }
    return temp2;
}
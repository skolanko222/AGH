#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  
  int value;
  struct tnode * next;

}tnode_templ;
void *add_2(tnode_templ **head, tnode_templ *elem);

struct tnode *add(struct tnode * head, int val);
tnode_templ * zwolnij(tnode_templ *head);
void wypisz(tnode_templ *head);

int main(void)
{
    tnode_templ *head = NULL;
    tnode_templ *a = malloc(sizeof(tnode_templ));
    a->value = 1;
    tnode_templ *b = malloc(sizeof(tnode_templ));
    b->value = 10;
    tnode_templ *c = malloc(sizeof(tnode_templ));
    c->value = 4;
    tnode_templ *d = malloc(sizeof(tnode_templ));
    d->value = 5;

    add_2(&head,a);
    //add_2(&head,&b);
    add_2(&head,d);
    add_2(&head,c);

    wypisz(head);

}
void *add_2(tnode_templ **head, tnode_templ *elem)
{
    if(*head == NULL)
    {
        *head = elem;
       
        elem->next = NULL;
        
    }
    else
    {
        tnode_templ *temp = *head;
        tnode_templ *prev = *head;
        while( (temp->next != NULL) && (temp->value <= elem->value) ) temp = temp->next;
        if(temp->next == NULL && temp->value <= elem->value)
        {
            temp->next = elem;
            elem->next = NULL;
        }
        else 
        {
            elem->next = temp;
            temp->next = elem;
            //prev->next = elem;
        }
        
    }   
}
void wypisz(tnode_templ *head)
{
    printf("head -> ");
    tnode_templ *temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        printf("['%d'] ->",temp->value);
        temp = temp->next;

    }
    if(temp != NULL) printf("['%d'] ->",temp->value);
    printf("NULL");

}
tnode_templ * zwolnij(tnode_templ *head)
{
    tnode_templ *temp = head;
    tnode_templ *next1;
    if(temp != NULL) next1 = head->next;
    while(temp != NULL && next1 != NULL)
    {
        free(temp);
        temp = next1;
        next1 = next1->next;
    }
    if(temp != NULL) free(temp);

    return NULL;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  char value;
  struct tnode * next;
}tnode_w; 

void wypisz(tnode_w *head);
tnode_w * zwolnij(tnode_w *head);
tnode_w * add_end (char val, struct  tnode *head);

int main(void)
{
    tnode_w * head = NULL;
    head = add_end('a',head);
    head = add_end('c',head);
    head = add_end('v',head);
    head = add_end('f',head);
    head = add_end('t',head);
    wypisz(head);

    zwolnij(head);

    return 0;
}
void wypisz(tnode_w *head)
{
    printf("head -> ");
    tnode_w *temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        printf("['%c'] ->",temp->value);
        temp = temp->next;

    }
    if(temp != NULL) printf("['%c'] ->",temp->value);
    printf("NULL");

}
tnode_w * zwolnij(tnode_w *head)
{
    tnode_w *temp = head;
    tnode_w *next1;
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
tnode_w * add_end (char val, struct  tnode *head)
{
    tnode_w *new = malloc(sizeof(tnode_w));
    if(!new){printf("Brak␣pamieci !\n"); return head ;}
    tnode_w *temp = head;
    new->value = val;
    new->next = NULL;
    if(head != NULL)
    {
        while(temp != NULL && temp->next != NULL) temp = temp->next;
        temp->next = new;
    return head;
    }
    if(head == NULL)
        return new;


}

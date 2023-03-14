#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  char value;
  struct tnode * next;
}tnode_w; 

void add_front (tnode_w **head,char val);
void wypisz(tnode_w *head);
tnode_w * zwolnij(tnode_w *head);

int main(void)
{
    tnode_w * head = NULL;
    add_front(&head, 'a');
    add_front(&head, 'c');
    add_front(&head, 'v');
    add_front(&head, 'f');
    add_front(&head, 't');
    
    wypisz(head);
    head = zwolnij(head);
    return 0;
}
void add_front (tnode_w **head,char val)
{
    tnode_w *new = malloc(sizeof(tnode_w));
    if(!new){printf("Brak␣pamieci !\n");return ;}
    
    new->value = val;
    new->next = *head;
    *head = new;


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

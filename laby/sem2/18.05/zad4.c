#include <stdio.h>
#include <stdlib.h>

typedef struct tnode 
{
  
  char *nazwisko;
  char plec;
  short rok;
  struct tnode * next;

}tnode_templ;
tnode_templ * add_end_2 (struct  tnode *ele, struct  tnode *head);

struct tnode *add(struct tnode * head, int val);
tnode_templ * zwolnij(tnode_templ *head);
void wypisz(tnode_templ *head);

int main(void)
{
    tnode_templ *head;
    tnode_templ *a = malloc(sizeof(tnode_templ));
    a->nazwisko = "Nowak";
    a->plec = 'm';
    a->rok = 2000;
    a->next = NULL;
    tnode_templ *b = malloc(sizeof(tnode_templ));
    a->nazwisko = "kowalski";
    b->plec = 'k';
    b->rok = 1970;
    b->next = NULL;

    add_end_2(a,head);
    //add_end_2(b,head);

    //zwolnij(head);


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
tnode_templ * add_end_2 (struct  tnode *ele, struct  tnode *head)
{
    tnode_templ *temp = head;
    ele->next = NULL;
    if(head != NULL)
    {
        while(temp != NULL && temp->next != NULL) temp = temp->next;
        temp->next = ele;
        return head;
    }
    if(head == NULL)
        return ele;
}
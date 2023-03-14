#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  char value;
  struct tnode * next;
}tnode_w; 

void wypisz(tnode_w *head);
tnode_w * zwolnij(tnode_w *head);
tnode_w * add_end_2 (struct  tnode *ele, struct  tnode *head);
tnode_w * usun(tnode_w *head,char val);
tnode_w * add_end (char val, struct  tnode *head);
tnode_w * usun_2(tnode_w *head,char val)
{
    tnode_w * temp = head, *prev = temp;
    tnode_w * nowa = NULL;
    while(temp->next != NULL)
    {  
            if((temp -> value == val) && (val > 'z' || val < 'A') )
            {
                prev->next = temp->next;
                nowa = add_end_2(temp,nowa);
                //printf("!!!!! \n");

            }
            if( (val <= 'z' && val >= 'A') && (temp -> value == val) ) 
            {
                prev->next = temp->next;
                nowa = add_end_2(temp,nowa);

            }
            if( (val <= 'z' && val >= 'a') && (temp -> value == val - 32) ) 
            {
                prev->next = temp->next;
                nowa = add_end_2(temp,nowa);

            }
            if( (val <= 'A' && val >= 'Z') && (temp -> value == val + 32) ) 
            {
                prev->next = temp->next;
                nowa = add_end_2(temp,nowa);

            }
            
            temp = temp->next;
            prev = temp;

    }
    
    return nowa;

}

int main(void)
{
    tnode_w * head = NULL;
    tnode_w * head_2 = NULL;
    head = add_end('a',head);
    head = add_end('t',head);
    head = add_end('o',head);
    head = add_end('k',head);
    head = add_end(' ',head);
    head = add_end('a',head);
    head = add_end('m',head);
    head = add_end(' ',head);
    head = add_end('a',head);
    head = add_end('l',head);
    head = add_end(' ',head);
    head_2 = usun_2(head,' ');
    
    wypisz(head);
    //wypisz(head_2);

    head = zwolnij(head);
    head_2 = zwolnij(head_2);

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
    printf("NULL\n");

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
tnode_w * add_end_2 (struct  tnode *ele, struct  tnode *head)
{
    tnode_w *temp = head;
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
tnode_w * usun(tnode_w *head,char val)
{
    tnode_w *temp = head, *prev = NULL;
    for(;temp != NULL; prev = temp, temp = temp->next)
    {
            if(temp -> value == val && (val > 'z' || val < 'A'))
            {
                prev->next = temp->next;
                free(temp);

            }
            if( (val <= 'z' && val >= 'A') && (temp -> value == val) ) 
            {
                prev->next = temp->next;
                free(temp);

            }
            if( (val <= 'z' && val >= 'A') && (temp -> value == val + 32) ) 
            {
                prev->next = temp->next;
                free(temp);

            }
            if( (val <= 'z' && val >= 'A') && (temp -> value == val - 32) ) 
            {
                prev->next = temp->next;
                free(temp);

            }

    }
    
    return head;

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

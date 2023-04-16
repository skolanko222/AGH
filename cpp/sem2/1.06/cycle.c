#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"

tnode * create (int var){
	tnode * wsk = malloc(sizeof (tnode));
	wsk->value = var;
	wsk->next = NULL;
return wsk;	
}

tnode* add_el(tnode* head, tnode* el)
{
    if(head == NULL)
    {
        tnode *ret = malloc(sizeof(tnode));
        ret = el;
        el->next = el;
        return ret;
    }
    else{
        el->next = head->next;
        head->next = el;
        return head;
    }

}
void print_list(tnode * head)
{
    if(!head) return;
    else{
        printf("%d -> ",head->value);
        tnode *temp = head;
        while(temp->next != head){
            temp = temp->next;
            printf("%d -> ",temp->value); 
        }
        printf("POCZATEK\n"); 
    }
}
void del_el(tnode** head, int var)
{
    if(!head) return;
    else{
        tnode *temp = *head;
        tnode *end = temp->next->next;
        do{
            temp = temp->next;
            
        }while((temp->next->next != end) && (temp->next->value != var));
       
            tnode *fre = temp->next;
            temp->next = fre->next;
            if(fre != *head) free(fre);
            else *head = fre;
    }
}
tnode* add_list(tnode* head1, tnode* head2)
{
    tnode *ret = malloc(sizeof(tnode));
    ret = head1;
    tnode *temp = head1->next;
    head1->next= head2->next;
    head2->next = temp;
    return ret;

}
void reverse(tnode* head)
{ 
    if (head == NULL)return;

    tnode* prev = NULL;
    tnode *current = head;
    tnode* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (head));
    head->next = prev;

}

void free_list(tnode** head)
{
    tnode *temp = (*head)->next;
    while(temp != *head) {free(temp);temp=temp->next;}
    free(*head);

}

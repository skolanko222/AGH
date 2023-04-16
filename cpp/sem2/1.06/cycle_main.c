#include <stdio.h>
#include "cycle.c"



int main(void)
{
    tnode *e1 = create(1);
    tnode *e2 = create(2);
    tnode *e3 = create(3);
    tnode *e4 = create(4);
    tnode *e5 = create(5);

    tnode *f1 = create(-1);
    tnode *f2 = create(-2);
    tnode *f3 = create(-3);
    tnode *f4 = create(-4);
    tnode *f5 = create(-5);

    tnode *head = add_el(NULL,e1);
    head = add_el(head,e2);
    head = add_el(head,e3);
    head = add_el(head,e4);
    head = add_el(head,e5);

    tnode *head_2 = add_el(NULL,f1);
    head_2 = add_el(head_2,f2);
    head_2 = add_el(head_2,f3);
    head_2 = add_el(head_2,f4);
    head_2 = add_el(head_2,f5);

    print_list(head);
    print_list(head_2);
    del_el(&head,4); 
    print_list(head);
    tnode *head_3 = add_list(head,head_2); //polaczona
    print_list(head_3);
    reverse(head_3);
    printf("odwrocona: \n");
    print_list(head_3);
    free_list(&head);

    return 0;
}
/*

    WERSJA W JEDNYM PLIKU

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct node *next;
}tnode;

tnode * create (int var);
tnode* add_el(tnode* head, tnode* el);
void print_list(tnode * head);
void del_el(tnode** head, int var);
tnode* add_list(tnode* head1, tnode* head2);
void reverse(tnode* head);
void free_list(tnode** head);

int main(void)
{
    tnode *e1 = create(1);
    tnode *e2 = create(2);
    tnode *e3 = create(3);
    tnode *e4 = create(4);
    tnode *e5 = create(5);

    tnode *f1 = create(-1);
    tnode *f2 = create(-2);
    tnode *f3 = create(-3);
    tnode *f4 = create(-4);
    tnode *f5 = create(-5);

    tnode *head = add_el(NULL,e1);
    head = add_el(head,e2);
    head = add_el(head,e3);
    head = add_el(head,e4);
    head = add_el(head,e5);

    tnode *head_2 = add_el(NULL,f1);
    head_2 = add_el(head_2,f2);
    head_2 = add_el(head_2,f3);
    head_2 = add_el(head_2,f4);
    head_2 = add_el(head_2,f5);

    print_list(head);
    print_list(head_2);
    del_el(&head,4); 
    print_list(head);
    tnode *head_3 = add_list(head,head_2); //polaczona
    print_list(head_3);
    reverse(head_3);
    printf("odwrocona: \n");
    print_list(head_3);
    free_list(&head);

    return 0;
}

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

}*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node_one_way
{
    char data;
    struct node_one_way *next;

}node;

node *add_sorted_one_way(node *head, node *elem);
void free_tnode(node * lista_obecna);
void wypisz(node *head);
node *link_2_sorted(node *head1, node *head2)
{
    node *temp = head1;
    node *temp_next = head1;
    node *ret = head2;
    while(temp != NULL)
    {
        temp_next = temp_next->next;
        ret = add_sorted_one_way(ret,temp);
        temp = temp_next;
    }
    return ret;
}

int main(void)
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *z = malloc(sizeof(node));
    z->data = 'z';
    z->next = NULL;
    node *a= malloc(sizeof(node));
    a->data = 'a';
    a->next = NULL;
    node *f= malloc(sizeof(node));
    f->data = 'f';
    f->next = NULL;
    node *c= malloc(sizeof(node));
    c->data = 'c';
    c->next = NULL;
    node *t= malloc(sizeof(node));
    t->data = 't';
    t->next = NULL;

    node *q = malloc(sizeof(node));
    q->data = 'q';
    q->next = NULL;
    node *h= malloc(sizeof(node));
    h->data = 'h';
    h->next = NULL;
    node *v= malloc(sizeof(node));
    v->data = 'v';
    v->next = NULL;
    head2 = add_sorted_one_way(head2,q);
    head2 = add_sorted_one_way(head2,h);
    head2 = add_sorted_one_way(head2,v);

    head1 = add_sorted_one_way(head1,t);
    head1 = add_sorted_one_way(head1,c);
    head1 = add_sorted_one_way(head1,f);
    head1 = add_sorted_one_way(head1,a);
    head1 = add_sorted_one_way(head1,z);
    //printf("%p %p",z->data,a2->data);


    wypisz(head1);
    wypisz(head2);

    
    node * res = link_2_sorted(head1,head2);
    wypisz(res);
    free_tnode(res);


    return 0;
}
node *add_sorted_one_way(node *head, node *elem) 
{
    node* current;
    //przypadek, gdy elem ma być przed HEAD
    if (head == NULL || elem->data < head->data) //head == NULL || <- jeżeli head może być null
    {
        elem->next = head;
        return elem;
    }
    else 
    {
        //szuka gdzie dołączyć element
        current = head;
        while (current->next != NULL && elem->data > current->next->data ) {
            current = current->next;
        }
        elem->next = current->next;
        current->next = elem;
        return head;
    }

}
void free_tnode(node * lista_obecna)
{
    if(lista_obecna->next != NULL){
        free_tnode(lista_obecna->next);
        free(lista_obecna);
    }
    else
        free(lista_obecna);

}
void wypisz(node *head)
{
    printf("head -> ");
    node *temp = head;
    while(temp != NULL)
    {
        printf("['%c'] ->",temp->data);
        temp = temp->next;

    }
    if(temp != NULL) printf("['%c'] ->",temp->data);
    printf("NULL\n");

}
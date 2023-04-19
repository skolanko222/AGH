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
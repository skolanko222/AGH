#include <stdio.h>
#include <stdlib.h>

typedef struct _tnode
{
    int value;
    struct _tnode * next;
    struct _tnode * prev;
}tnode;
void print_list_next(tnode* lista_obecna);
void print_list_prev(tnode* lista_obecna);
tnode * add_first(tnode* head, tnode* el);
tnode * add_last(tnode* head, tnode* el); 
tnode * remove_and_return(tnode **head, int var);
tnode * del_el(tnode **head, int var);
tnode * del_el_2(tnode** head, int var);
tnode *add_sort(tnode *head, tnode *elem);
void free_tnode(tnode ** lista_obecna);
tnode* div_list( tnode** head);

int main(void)
{
    tnode *head = malloc(sizeof(tnode));
    head = NULL;
    tnode *a = malloc(sizeof(tnode));
    a->value = 15;
    tnode *b = malloc(sizeof(tnode));
    b->value = 14;
    tnode *c = malloc(sizeof(tnode));
    c->value = 13;
    tnode *d = malloc(sizeof(tnode));
    d->value = 16;
    tnode *b2 = malloc(sizeof(tnode));
    b2->value = 15;
    head = add_first(head,a);
    head = add_first(head,b);
    head = add_first(head,c);
    head = add_last(head,b2);
    head = add_last(head,d);

    print_list_next(head);
    print_list_prev(head->next->next->next->next);
    
    tnode *lista_usunieta = NULL; 
    
    lista_usunieta = del_el(&head,13);
    tnode *elem = del_el_2(&head,14);
    printf("usunieto: %d\n",elem->value);
    print_list_next(head);
    print_list_prev(head->next->next);
    print_list_next(lista_usunieta);
    //print_list_prev(lista_usunieta->next);
    
    tnode *x = malloc(sizeof(tnode));
    x->value = 3;
    tnode *z = malloc(sizeof(tnode));
    z->value = 14;
    
    head = add_sort(head,x);
    head = add_sort(head,z);
    
    print_list_next(head);
    tnode *parzyste = div_list(&head);
    print_list_next(head); //nieparzyste
    print_list_next(parzyste); //parzyste

    free_tnode(&head);
    free_tnode(&lista_usunieta);

    return 0;
}
void print_list_next(tnode* lista_obecna)
{
    if(lista_obecna->next == NULL && lista_obecna->prev == NULL) 
        printf("NULL - ['%d'] - NULL\n",lista_obecna->value);
    else
    {
    
        if(lista_obecna->prev == NULL) 
        {
            printf("NULL - ['%d'] - ",lista_obecna->value);
            print_list_next(lista_obecna->next); 
        }
        else if(lista_obecna->next == NULL) printf("['%d'] - NULL\n",lista_obecna-> value);
        else 
        {
            printf("['%d'] - ",lista_obecna->value);
            print_list_next(lista_obecna->next);
        }
    }
}
void print_list_prev(tnode* lista_obecna)
{
    if(lista_obecna->next == NULL && lista_obecna->prev == NULL) 
        printf("NULL - ['%d'] - NULL\n",lista_obecna->value);
    else
    {
        if(lista_obecna->next == NULL) 
        {
            printf("NULL - ['%d'] - ",lista_obecna->value);
            print_list_prev(lista_obecna->prev); 
        }
        else if(lista_obecna->prev == NULL) printf("['%d'] - NULL\n",lista_obecna-> value);
        else 
        {
            printf("['%d'] - ",lista_obecna->value);
            print_list_prev(lista_obecna->prev);   
        }
    }

}
tnode* add_first(tnode* head, tnode* el)
{
    if(head != NULL)       
        head->prev = el;

    el->prev = NULL;
    el->next = head;
    return el;

}
tnode* add_last(tnode* head, tnode* el)
{
    if(head == NULL)
    {
        el->next = NULL;
        el->prev = NULL;
        return el;
    }
    tnode *temp = head; 
    while(temp->next != NULL) temp = temp->next;

    temp->next = el;
    el->next = NULL;
    el->prev = temp;

    return head;
}
tnode* remove_and_return(tnode **head, int var)
{
    tnode *temp = *head;
    while(temp->next != NULL && temp->value != var) temp = temp->next;
    
    if(temp->next == NULL && temp->value != var) 
    { 
        return NULL;
    }
    else if(temp->next == NULL && temp->value == var)
    {
        (temp->prev)->next = NULL; 
       
        temp->prev = NULL;
        temp->next = NULL;
        return temp;

    }
    else if(temp->next == NULL && temp->value == var)
    {
        (temp->prev)->next = NULL; 
       
        temp->prev = NULL;
        temp->next = NULL;
        return temp;

    }
    else if(temp->prev == NULL && temp->value == var)
    {
        *head = temp->next;
        (temp->next)->prev = NULL;

        temp->prev = NULL;
        temp->next = NULL;
        return temp;

    }
    else if(temp->value == var) 
    {
        (temp->prev)->next = temp->next; 
        (temp->next)->prev = temp->prev;

        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
}
tnode * del_el(tnode **head, int var)
{
    tnode * _return = *head;
    
    tnode * _return_list = malloc(sizeof(tnode)); _return_list = NULL;
    while(_return != NULL)
    {
        _return = remove_and_return(head,var);
        if(_return != NULL) _return_list = add_last(_return_list,_return);

    }

    return _return_list;

}
tnode * del_el_2(tnode** head, int var)
{
    tnode * _return = *head;
    _return = remove_and_return(head,var);
    //tnode * first = _return;
    
    //while(_return != NULL)
    {
        //_return = remove_and_return(head,var);
        //free(_return);
        //if(_return != NULL) _return_list = add_last(_return_list,_return);

    }

    return _return;


}
tnode *add_sort(tnode *head, tnode *elem)
{
    if(head == NULL)
    {
        head = elem;
        elem->prev = NULL;
        elem->next = NULL;
        return head;
    }
    else
    {
        tnode *temp = head;

        while( (temp->next != NULL) && (temp->value <= elem->value) ) temp = temp->next;
        if(temp->next == NULL && temp->value <= elem->value)
        {
            elem->prev = temp;
            temp->next = elem;
            elem->next = NULL;
        }
        else 
        {
            elem->prev = temp->prev;
            elem->next = temp;
            if(temp->prev != NULL) 
                (temp->prev)->next = elem;
            temp->prev = elem;
        }
        while(temp->prev != NULL) temp = temp->prev; 
        return temp;
    }   
}
void free_tnode(tnode ** lista_obecna)
{
    if((*lista_obecna)->next != NULL){
        free_tnode(&(*lista_obecna)->next);
        free(*lista_obecna);
    }
    else
        free(*lista_obecna);

}
tnode* div_list( tnode** head)
{
    tnode *parzyste = malloc(sizeof(tnode));
    //tnode *nieparzyste = malloc(sizeof(tnode));
    parzyste = NULL;
    //nieparzyste = NULL;
    tnode *temp = *head;
    while(temp->next != NULL) 
    {
        int wartosc = temp->value;
        if(wartosc%2==0) parzyste = add_first(*head,del_el_2(head,wartosc));
        temp = temp->next;
    }
    return parzyste;
}
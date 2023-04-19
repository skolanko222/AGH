#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    char value;
    struct tnode * next;
    struct tnode * prev;
};

struct tnode * add(struct tnode * elem_obecny, struct tnode *elem)
{
    if(elem_obecny == NULL)
    {
        struct tnode * pole_nowe = malloc(sizeof(struct tnode));

        pole_nowe = elem;
        pole_nowe->prev = NULL;
        pole_nowe->next = NULL;

        return pole_nowe;
    }
    else if(elem_obecny->value >= elem->value )
    {
        struct tnode * temp = elem_obecny;
        //el
        
        return elem;

    }
    else return add(elem_obecny->next,elem);


}

void wypisz(struct tnode *lista_obecna, char kierunek);
int main(void)
{
    struct tnode *z = malloc(sizeof(struct tnode));
    z->value = 'z';
    
    struct tnode *c = malloc(sizeof(struct tnode));
    c->value = 'c';

    struct tnode *a = malloc(sizeof(struct tnode));
    a->value = 'a';

    struct tnode *b = malloc(sizeof(struct tnode));
    b->value = 'b';

    struct tnode *t = malloc(sizeof(struct tnode));
    t->value = 't';
    
    struct tnode * head = add(NULL,z);
    head = add(head,c);
    add(head,a);
    add(head,b);
    add(head,t);
    wypisz(head, 'N');

    return 0;
}
void wypisz(struct tnode *lista_obecna, char kierunek)
{
    if(lista_obecna->next == NULL && lista_obecna->prev == NULL) printf("NULL <-> ['%c'] <-> NULL",lista_obecna->value);
    else if(kierunek == 'P')
    {
        if(lista_obecna->next == NULL) 
        {
            printf("NULL <-> ['%c'] <-> ",lista_obecna->value);
            wypisz(lista_obecna->prev,'P'); 
        }
        else if(lista_obecna->prev == NULL) printf("['%c'] <-> NULL",lista_obecna-> value);
        else 
        {
            printf("['%c'] <-> ",lista_obecna->value);
            wypisz(lista_obecna->prev,'P');   
        }
    }
    else if(kierunek == 'N')
    {
        if(lista_obecna->prev == NULL) 
        {
            printf("NULL -> ['%c'] <-> ",lista_obecna->value);
            wypisz(lista_obecna->next,'N'); 
        }
        else if(lista_obecna->next == NULL) printf("['%c'] <- NULL",lista_obecna-> value);
        else 
        {
            printf("['%c'] <-> ",lista_obecna->value);
            wypisz(lista_obecna->next,'N');   
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    char value;
    struct tnode * next;
    struct tnode * prev;
};

struct tnode *add(struct tnode * lista_obecna, char val);
void wypisz(struct tnode *lista_obecna, char kierunek);
void free_tnode(struct tnode * lista_obecna);

int main(void)
{
    struct tnode * head = add(NULL,'z');
    add(head,'c');
    add(head->next,'a');
    add(head->next->next,'f');
    add(head->next->next->next,'t');

    printf("\n");
    wypisz(head,'N');
    printf("\n");

    free_tnode(head);

    return 0;
}

void wypisz(struct tnode *lista_obecna, char kierunek)
{
    if(lista_obecna->next == NULL && lista_obecna->prev == NULL) printf("NULL <-> ['%c'] <-> NULL",lista_obecna->value);
    else if(kierunek == 'P')
    {
        if(lista_obecna->next == NULL) 
        {
            printf("NULL -> ['%c'] ->",lista_obecna->value);
            wypisz(lista_obecna->prev,'P'); 
        }
        else if(lista_obecna->prev == NULL) printf("['%c'] -> NULL",lista_obecna-> value);
        else 
        {
            printf("['%c'] <->",lista_obecna->value);
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
struct tnode *add(struct tnode * lista_obecna, char val)
{
    struct tnode * pole_nowe = malloc(sizeof(struct tnode));
    if(lista_obecna != NULL) lista_obecna -> next = pole_nowe;
    pole_nowe->prev = lista_obecna;
    pole_nowe->value = val;
    pole_nowe->next = NULL;
    return pole_nowe;
}
void free_tnode(struct tnode * lista_obecna)
{
    if(lista_obecna->next != NULL){
        free_tnode(lista_obecna->next);
        free(lista_obecna);
    }
    else
        free(lista_obecna);

}
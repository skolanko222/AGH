#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char value;
    struct tnode * next;
    struct tnode * prev;
}tnode_templ;

void wypisz(struct tnode *lista_obecna, char kierunek);
void free_tnode(struct tnode * lista_obecna);
struct tnode *add(struct tnode * head, char val);

int main(void)
{
    tnode_templ * head = add(NULL,'z');
    head = add(head,'c');
    head = add(head,'a');
    head = add(head,'f');
    head = add(head,'t');
    
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

void free_tnode(struct tnode * lista_obecna)
{
    if(lista_obecna->next != NULL){
        free_tnode(lista_obecna->next);
        free(lista_obecna);
    }
    else
        free(lista_obecna);

}

struct tnode *add(struct tnode * head, char val)
{
    tnode_templ * new = malloc(sizeof(tnode_templ));
    if(!new) return head;
    
    if(head == NULL) {new->prev = NULL;
    new->next = NULL;
    new->value = val;
    return new;
    }
    
    new->next = NULL;
    new->value = val;
    
    if(head != NULL)
    {
        tnode_templ *temp = head;
        while(temp->next) temp = temp->next; //przesuwanie listy

        temp->next = new;
        new->prev = temp; 
    }

    return head;
}
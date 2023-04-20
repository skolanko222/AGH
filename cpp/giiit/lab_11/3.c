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
struct tnode *remove_c(struct tnode ** head, char val);

int main(void)
{
    tnode_templ * head = add(NULL,'a');

    head = add(head,'d');
    head = add(head,'b');
    head = add(head,'a');
    head = add(head,'f');
    head = add(head,'g');
    head = add(head,'a');

    wypisz(head,'N');
    printf("\n");
    head = remove_c(&head,'a');
    wypisz(head->next->next->next,'P');
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
    if(!new) return NULL;
    
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
struct tnode *remove_c(struct tnode ** head, char val) //MUSI BYÆ PODWÓJNY, BO NIE DA SIE INACZEJ ZROBIÆ FREE!!!! 
{
    tnode_templ **temp = head;
    tnode_templ *temp_n;
    char war = 0;
    while(*temp != NULL) 
    {
        war = 0;
        if((*temp)->value == val)
        {
            if((*temp)->prev != NULL) ((*temp)->prev)->next = (*temp)->next;
            if((*temp)->next != NULL) ((*temp)->next)->prev = (*temp)->prev;
            war = 1;
        }

        if((*temp)->next != NULL){
            temp_n = (*temp)->next;
            if(war == 1) {printf("%c\n",(*temp)->value); free(*temp); } //free nir dzia³a
            *temp = temp_n;
        }
        else
        {
            if(war == 1) {printf("%c\n",(*temp)->value); free(*temp); }
            break;
        }
            
       
    }
    
    while((*temp)->prev != NULL) { (*temp) = (*temp)->prev;}
    return (*temp);
}
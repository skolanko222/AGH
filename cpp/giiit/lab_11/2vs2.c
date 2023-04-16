#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char value;
    struct tnode * next;
    struct tnode * prev;
}tnode_templ;

void wypisz(tnode_templ *lista_obecna, char kierunek);
void free_tnode(tnode_templ * lista_obecna);
tnode_templ *add(tnode_templ * head, char val);
tnode_templ *add_2(tnode_templ *head, tnode_templ *elem)
{
    if(head == NULL)// jeśli pierwszy el listy
    {
        head = elem;
        elem->prev = NULL;
        elem->next = NULL;
        return head;
    }
    else
    {
        tnode_templ *temp = head;

        while( (temp->next != NULL) && (temp->value <= elem->value) ) temp = temp->next;
        if(temp->next == NULL && temp->value <= elem->value)//jeżeli ma być na końcu listy
        {
            elem->prev = temp;
            temp->next = elem;
            elem->next = NULL;
        }
        else //jeżeli ma wsadzidzić gdzieś w środku
        {
            elem->prev = temp->prev;
            elem->next = temp;
            if(temp->prev != NULL) //jeżeli ma być na początku listy
                (temp->prev)->next = elem;
            temp->prev = elem;
        }
        while(temp->prev != NULL) temp = temp->prev; //powrót
        return temp;
    }   
}
int main(void)
{
    tnode_templ *z = malloc(sizeof(tnode_templ));
    z->value = 'z';
    tnode_templ *a= malloc(sizeof(tnode_templ));
    a->value = 'a';
    tnode_templ *f= malloc(sizeof(tnode_templ));
    f->value = 'f';
    tnode_templ *c= malloc(sizeof(tnode_templ));
    c->value = 'c';
    tnode_templ *t= malloc(sizeof(tnode_templ));
    t->value = 't';
    tnode_templ * head = add_2(NULL,a);
    head = add_2(head, c);
    head = add_2(head, z);
    head = add_2(head, f);
    head = add_2(head, t); 
    wypisz(head,'N');
    printf("\n");
    wypisz(head->next->next->next->next,'P');

     
    free_tnode(head);

    return 0;
}

void wypisz(struct tnode *lista_obecna, char kierunek)
{
    if(lista_obecna->next == NULL && lista_obecna->prev == NULL) 
        printf("NULL -> ['%c'] <- NULL",lista_obecna->value);
    
    else if(kierunek == 'P')
    {
        if(lista_obecna->next == NULL) 
        {
            printf("NULL -> ['%c'] <-> ",lista_obecna->value);
            wypisz(lista_obecna->prev,'P'); 
        }
        else if(lista_obecna->prev == NULL) printf("['%c'] <- NULL",lista_obecna-> value);
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
    
    if(head == NULL) {
    new->prev = NULL;
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
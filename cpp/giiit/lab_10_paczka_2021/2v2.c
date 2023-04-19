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
tnode_templ *add(struct tnode * head, char val);
tnode_templ *add_2(tnode_templ *head, tnode_templ *elem)
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
    tnode_templ *temp = head;

    while( (temp->value <= elem->value) && (temp->next != NULL) ) temp = temp->next;

    elem->prev = temp->prev;
    elem->next = temp;
    if(temp->prev != NULL) (temp->prev)->next = elem;
    temp->prev = elem;
    while(temp->prev != NULL) temp = temp->prev;

    return temp;
    }   
}
int main(void)
{
    tnode_templ z;
    z.value = 'z';
    tnode_templ a;
    a.value = 'a';
    tnode_templ f;
    f.value = 'f';
    tnode_templ c;
    c.value = 'c';
    tnode_templ t;
    t.value = 'c';
    tnode_templ * head = add_2(NULL,&z);
    head = add_2(head, &c);
    head = add_2(head, &a);
    head = add_2(head, &f);
    head = add_2(head, &t); //nie działa
    wypisz(head,'N');

    //printf("%c %c %c",head->value,(head->next)->value);
     
    free_tnode(head);

    return 0;
}

void wypisz(struct tnode *lista_obecna, char kierunek)
{
    if(lista_obecna->next == NULL && lista_obecna->prev == NULL) 
        printf("NULL <-> ['%c'] <-> NULL",lista_obecna->value);
    
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
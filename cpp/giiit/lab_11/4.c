#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    char value;
    struct tnode * next;
    struct tnode * prev;
}tnode_templ;

typedef struct tnode1
{
    char *value;
    struct tnode1 * next;
    
}tnode_templ2;

void wypisz(struct tnode *lista_obecna, char kierunek);
void free_tnode(struct tnode * lista_obecna);
struct tnode *add(struct tnode * head, char val);
struct tnode *remove_c(struct tnode * head, char val);
tnode_templ2 *split(struct tnode * head, char val)
{
    tnode_templ *temp = head;
    tnode_templ **arr = malloc(sizeof(tnode_templ));
    short i = 1;
    while(temp->next != NULL)
    {        
        if(temp->value = val)
        {
            arr[i-1] = temp;
            arr = realloc(arr,sizeof(tnode_templ) * ++ i);

        }

        temp = temp->next;
    }

    temp = (*arr);
    tnode_templ2 *ret;

}
tnode_templ2 *add_one_way(struct tnode * head)
{
    tnode_templ2 * new = malloc(sizeof(tnode_templ2));
    if(!new) return NULL;
    
    if(head == NULL) {
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

int main(void)
{
    tnode_templ2 * head = add_one_way(NULL,'a');
    head = add_one_way(head,'d');
    head = add_one_way(head,'b');
    head = add(head,'f');
    head = add(head,'e');
    head = add(head,'t');
    head = add(head,'l');
    head = add(head,'x');
    head = add(head,'q'); 



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
struct tnode *remove_c(struct tnode * head, char val)
{
    tnode_templ *temp = head;
    while(temp->next != NULL && temp->value != val) temp = temp->next;
    if(temp->next == NULL && temp->value != val) printf("Brak elementu w liscie!\n");
    else if(temp->prev == NULL && temp->value == val)
    {
        (temp->next)->prev = NULL;
        tnode_templ *temp2 = temp->next;
        free(temp);
        return temp2;

    }
    else if(temp->next == NULL && temp->value == val)
    {
        (temp->prev)->next = NULL;
        tnode_templ *temp2 = temp->prev;
        free(temp);
        return temp2;
    }
    else
    {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        free(temp);
        return head;
    }
}
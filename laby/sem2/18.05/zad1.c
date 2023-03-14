#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  int value;
  struct tnode * next;  
}tnode_w; 

void wypisz(tnode_w *head);
tnode_w * zwolnij(tnode_w *head);
tnode_w * add_end_2 (struct  tnode *ele, struct  tnode *head);

int main(void)
{
    int i = 0;
    int war = 0;
    tnode_w *temp2;
    
    tnode_w *L_1 = NULL, *L_2 = NULL;
    scanf("%d",&i);
    while(i < 20)
    {
        
        tnode_w *temp = malloc(sizeof(struct tnode));
        temp->value = i;
        temp->next = NULL;
        temp2 = L_2;
        if(i == 0 || war == 1)
        {
            L_1 = add_end_2(temp,L_1);
            L_2 = add_end_2(temp,L_2);
            //war = 1;
            //temp2 = L_2->next;
        }
        else if((i%2)==0) 
        {
        L_1 = add_end_2(temp,L_1);
        printf("D %d\n",temp->value);
        }
        else if(i%2!=0) 
        {
            L_2 = add_end_2(temp,L_2);
            printf("D %d\n",temp->value);
            temp2 = L_2->next;
        }

        scanf("%d",&i);
    }
    wypisz(L_1);
    printf("\n");
    wypisz(L_2);
    zwolnij(L_1);
    zwolnij(L_2);
    return 0;
}

void wypisz(tnode_w *head)
{
    printf("head -> ");
    tnode_w *temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        printf("['%d'] ->",temp->value);
        temp = temp->next;

    }
    if(temp != NULL) printf("['%d'] ->",temp->value);
    printf("NULL");

}
tnode_w * zwolnij(tnode_w *head)
{
    tnode_w *temp = head;
    tnode_w *next1;
    if(temp != NULL) next1 = head->next;
    while(temp != NULL && next1 != NULL)
    {
        free(temp);
        temp = next1;
        next1 = next1->next;
    }
    if(temp != NULL) free(temp);

    return NULL;
}
tnode_w * add_end_2 (struct  tnode *ele, struct  tnode *head)
{
    tnode_w *temp = head;
    ele->next = NULL;
    printf("Df %d\n",ele->value);
    if(head != NULL)
    {
        while(temp != NULL && temp->next != NULL) temp = temp->next;
        temp->next = ele;
        return head;
    }
    if(head == NULL)
        return ele;
}
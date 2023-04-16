#include <iostream>
#include "SimplyStruct.h"

TItem *InitItem()
{
    TItem *temp = (TItem *)malloc(sizeof(TItem));
    temp -> next = NULL;
    return temp;

}

void show(TItem *head)
{
    TItem * temp = head;
    std::cout << "Aktualny stan listy:" << std::endl;
    std::cout << "<";
    while(temp != NULL)
    {
        std::cout << temp->value;
        if(temp->next != NULL)
            std::cout << ",";
        temp = temp->next;

    }
    std::cout << ">";
    printf("\n");
}

void push(TItem **head, int value)
{
    TItem * node = InitItem();
    node->value = value;
    node->next = *head;
    *head = node;

}

int pop(TItem **head)
{
    int value = (*head)->value;
    TItem * temp = *head;
    *head = (*head)->next;
    free(temp);
    return value;
}

void clear(TItem **head)
{
    while(*head != NULL)
        pop(head);

}
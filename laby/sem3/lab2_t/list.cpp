#include <iostream>
#include "list.h"

void print_list(list *head)
{
    std::cout << "head -> ";
    list *temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        std::cout <<"[" << temp->value << "] -> ";
        temp = temp->next;

    }
    if(temp != NULL) std::cout <<"[" << temp->value << "] -> ";
    std::cout << "NULL";

}
list * free_list(list *head)
{
    list *temp = head;
    list *next1;
    if(temp != NULL) next1 = head->next;
    while(temp != NULL && next1 != NULL)
    {
        delete temp;
        temp = next1;
        next1 = next1->next;
    }
    if(temp != NULL) delete temp;

    return NULL;
}
list *add_list(list * head, int val)
{
    list * temp = new list;
    if(!temp) return head;
    
    if(head == NULL) {
    temp->next = NULL;
    temp->value = val;
    return temp;
    }
    
    temp->next = NULL;
    temp->value = val;
    
    if(head != NULL)
    {
        list *temp2 = head;
        while(temp2->next) temp2 = temp2->next;

        temp2->next = temp;
    }

    return head;
}

list * add_end (list *ele, list *head)
{
    list *temp = head;
    ele->next = NULL;

    if(head != NULL)
    {
        while(temp != NULL && temp->next != NULL) temp = temp->next;
        temp->next = ele;
        return head;
    }
    if(head == NULL)
        return ele;
}
void *add_sorted(list **head, int val)
{
    list *elem = new list;
    elem->value = val;
    elem->next = NULL;

    if(*head == NULL)
    {
        *head = elem;
       
        elem->next = NULL;
        head = &elem;
    }
    else
    {
        list *temp = *head;
        while( (temp->next != NULL) && (temp->value <= elem->value) ) temp = temp->next;
        if(temp->next == NULL && temp->value <= elem->value)
        {
            temp->next = elem;
            elem->next = NULL;
        }
        else 
        {
            elem->next = temp;
            temp->next = elem;
        }
        
    }   
}
#include <iostream>
#include <cstdlib>

#include "list.h"

int main(void)
{
    list *head;

    add_sorted(&head,9);
    add_sorted(&head,10);
    add_sorted(&head,0);
    //add_sorted(&head,-7);


    print_list(head);

    free_list(head);

    

    return 0;
}
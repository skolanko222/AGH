struct list
{ 
    int value;
    struct list *next;
};

void print_list(list *head);
list * free_list(list *head);
list *add_list(list * head, int val);
void *add_sorted(list **head, int val);
list * add_end (list *ele, list *head);
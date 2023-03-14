#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Set of given last node position to its proper position
typedef struct file
{
    short int quan;
    char * word;
    struct file * next;
}file_p;
file_p *parition(file_p *first, file_p *last)
{
	//Get first node of given linked list
	file_p *pivot = first;
	file_p *front = first;
	int temp = 0;
    char *temp_c;
	while (front != NULL && front != last)
	{
		if (front->quan > last->quan)
		{
			pivot = first;
			//Swap node value
			temp = first->quan;
			first->quan = front->quan;
			front->quan = temp;

            temp_c = first->word;
            first->word = front->word;
			front->word = temp_c;
			//Visit to next node
			first = first->next;
		}
		//Visit to next node
		front = front->next;
	}
	//Change last node value to current node
	temp = first->quan;
	first->quan = last->quan;
	last->quan = temp;
    temp_c = first->word;
    first->word = front->word;
	front->word = temp_c;
	return pivot;
}
//Perform quick sort in given linked list
void quick_sort(file_p *first, file_p *last)
{
	if (first == last)
	{
		return;
	}
	file_p *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
	{
		quick_sort(pivot->next, last);
	}
	if (pivot != NULL && first != pivot)
	{
		quick_sort(first, pivot);
	}
}

file_p *add_2(file_p *head, file_p *elem);
char *read_File(FILE *pFile); // FILE -> char *
file_p * search_add(char *word, file_p *list);
file_p *last_node(file_p *head);
void free_tnode(file_p * lista_obecna);

int main(int argv, char *argc[])
{
    argc[1] = "txt.txt";
    char enq;
    FILE * pFile = fopen (argc[1], "r") ;
    char *text = read_File(pFile);

    file_p *head = NULL;
    char *token = strtok(text,"' \t\n.,;:\\[]{}- - \"()*/»?—");
    while(token)
    {
        if(token[0]>64 && token[0]<91) token[0] += 32;
        head = search_add(token,head);
        token = strtok(NULL,"' \' \t\n.,;:\\[]{}- - \"!()*/»?—");  
    }
    
    file_p *temp = head;
    
    FILE * F_Out;
    file_p *last = last_node(head);
    printf("Sorted by amount? (Y/N)  ");
    scanf("%c",&enq);

    if(enq == 'Y' || enq == 'y' ) quick_sort(head,last);
    
    F_Out = fopen("out.txt","w");
    do
    {  
        printf("%d %s \n",temp->quan,temp->word);
        fprintf(F_Out,"\"%s'\" : %d\n",temp->word,temp->quan);  
        temp = temp->next;
    }while(temp != NULL);   


    free(text);
    free_tnode(head);
    //free(head);
    return 0;
}
file_p *last_node(file_p *head)
{
	file_p *temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}
file_p *add_2(file_p *head, file_p *elem) //napisać funkcję dodającą el. do posorotwanej listy
{
    file_p* current;
    //przypadek, gdy elem ma być przed HEAD
    if (strcmp(elem->word,head->word) < 0 ) //head == NULL || <- jeżeli head może być null
    {
        elem->next = head;
        return elem;
    }
    else 
    {
        /* Locate the node before the point of insertion */
        current = head;
        while (current->next != NULL && strcmp(elem->word,current->next->word) > 0 ) {
            current = current->next;
        }
        elem->next = current->next;
        current->next = elem;
        return head;
    }

}
char *read_File(FILE *pFile) // FILE -> char *
{
    char *text = malloc(sizeof(char));
    char c = '\0';
    int mem = 1;
    int i = 0;
    if(pFile) 
    {
        while(c != EOF)
        {
            c = fgetc(pFile);
            text = realloc(text,(++mem)*sizeof(char));
            if(c == EOF) text[i] = '\0';
            else text[i++] = c;
        }
        fclose(pFile);
    }
    return text;
}
file_p * search_add(char *word, file_p *list)
{
    file_p *temp = list;
    if(temp != NULL)
    {
        while(temp->next != NULL && strcmp(temp->word,word)) temp = temp->next;
        
        if(strcmp(temp->word,word) && temp->next == NULL) //jeżeli nie ma w liście danego elementu
        {
            file_p *new = malloc(sizeof(file_p));
            
            new->quan = 1;
            new->word = word;
            new->next = NULL;
            list = add_2(list, new); //dodajemy go do listy posortowanej  
        }
        else if(!strcmp(temp->word,word)) temp->quan++;
                
        return list;
    }
    else //tworzymy listę, jeżeli nie istnieje
    {
        temp = malloc(sizeof(file_p));
        temp->next = NULL;
        temp->quan = 1;
        temp->word = word;
        return temp;
    }
}
void free_tnode(file_p * lista_obecna)
{
    if(lista_obecna->next != NULL){
        free_tnode(lista_obecna->next);
        free(lista_obecna);
    }
    else
        free(lista_obecna);

}
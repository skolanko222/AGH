#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct file
{
    short int quan;
    char * word;
    struct file * next;
}file_p;

file_p *add_2(file_p *head, file_p *elem);
char *read_File(FILE *pFile); // FILE -> char *
file_p * search_add(char *word, file_p *list);
void free_tnode(file_p * lista_obecna);

int main(int argv, char *argc[])
{
    argc[1] = "txt.txt";
    FILE * pFile = fopen (argc[1], "r") ;
    char *text = read_File(pFile);

    file_p *head = NULL;
    char *token = strtok(text," \t\n.");
    while(token)
    {
        head = search_add(token,head);
        token = strtok(NULL," \t\n.");  
    }
    
    file_p *temp = head;
    
    FILE * F_Out;
    printf("NULL -> ");
    F_Out = fopen("out.txt","w");
    do
    {  
        fprintf(F_Out,"\"%s\" : %d\n",temp->word,temp->quan); 
        printf("[\"%s\" : %d] -> ",temp->word,temp->quan);
        temp = temp->next;
    }while(temp != NULL);   
    printf("NULL");
    free(text);
    free_tnode(head);
    //free(head);
    return 0;
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
    char *text = malloc(1);
    char c;
    int mem = 1;
    int i = 0;
    if(pFile) 
    {
        while((c = fgetc(pFile)) != EOF)
        {
            text = realloc(text,++mem);
            text[i++] = c;
        }
        text = realloc(text,++mem);
        text[i+1] = '\0';
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
#include <stdio.h>


//kolejka LIFO - wrzucamy od góry kulki
    //STOS jest liniową strukturą LIFO 
    // dodawanie i usuwanie Z GÓRY

//kolejka FIFO - wrzucamy od dołu kulki

void read(int *arr);
void add(int *arr);
void delete(int *arr);
#define N 10

int main(void)
{

    int arr[N]={1,2,3,4,5,6,7,8,9,10}, i=0;
    do{
    printf("1. Czytaj od dna \n2. Dodaj do stosu\n3. Zbierz ze stosu\n\n");
    printf("Wybor: ");
    scanf("%d ",&i);

    switch(i)
    {
    case 1:
        read(arr); break;
    case 2:
        add(arr); break;
    case 3:
        delete(arr); break;
    default:
        printf("BLAD! \n"); break;
    }

    }while(!(i>0 && i<4));


    return 0;
}

void read(int *arr)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d ",arr[i]);
    }

}
void add(int *arr)
{ 
    //zwykłe dodanie czegoś do tablicy

}
void delete(int *arr)
{

//zwykłe usunięcie czegoś z tablicy

}
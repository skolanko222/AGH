#include <stdlib.h>

int cmpr(const void *a, const void *b);


void sort_wstawianie(long int * arr, int size)
{
	for(int i = 1; i < size; i++)
	{
		long int temp = arr[i];
		int j = i - 1;
		while(j > 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

void sort_jakis(long int * arr, int size)
{
	qsort(arr, size, sizeof(int),cmpr);
}

int cmpr(const void *a, const void *b)
{
	return *((int*)a) > *((int*)b) ? -1 : 1; 
}
#include <stdio.h>



int main(void)
{
    char arr[] = {'a','b','G','h','T','u'};

    int size = sizeof(arr)/sizeof(char)-1;

    char arr_CAP[size];
    char arr_sml[size];

   int j=0, k=0;

    for(int i=0; i <= size; i++)
        {
            if(arr[i]>=65 && arr[i]<=90)
            {
                arr_CAP[j++] = arr[i];
            }
            if(arr[i]>=97 && arr[i]<=121)
            {
                arr_sml[k++] = arr[i];
            }
        }



    for(int i = 0; i <= k-1; i++)
    {

        printf("%c ",arr_sml[i]);

    }


    return 0;
}
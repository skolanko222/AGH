#include <stdio.h>
int suma (int *tab, int len);
int min (int *tab, int len);
void swap_rows(int n, int (*TAB)[n], int x, int y);
void swap_tab(int *A, int *B, int n);
void sort(int row, int col, int arr[][col]);
void swap(int*a, int*b);
void print_tab_all(int y,int a[][y], int x);

int main(void)
{
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    //int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    
    sort(3, 6, tab_A);
    print_tab_all(6,tab_A,3);


    return 0;
}
void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}

int min (int *tab, int len) 
{ 
    int ind = 0;
    for (int i = 1; i < len; i++)  
    if(tab[i] < tab[ind])
            ind = i; 
    return ind;

}
int suma (int *tab, int len)
{ 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;
}
void swap_tab(int *A, int *B, int n)
{

    for(int i = 0; i < n; i++)
    {
        swap(A+i,B+i);
    }

}

void swap_rows(int n, int (*TAB)[n], int x, int y)
{

   swap_tab(TAB[x],TAB[y], n);

}

void sort(int row, int col, int arr[][col])
{
    int min_w[row];
    int temp;

    for(int i = 0; i < row; i++)
    {
        min_w[i] = min(arr[i], col);
    }

    for(int i = 0; i < row; i++)
    {
        temp = min(min_w + i,row - i);
        for(int j = 0; j < row; j++)
        {
            if(min_w[j] == temp)
            {
                swap_rows(col, arr, i, j);
                swap(min_w + i,min_w + j);
            }

        }


    }
    


}
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}
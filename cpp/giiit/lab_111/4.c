#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    long offset = ((long)(rand())%10L);
    int y = rand()%10;
    int x = 123;
    FILE *fp = fopen ("myfile.bin","rb+");
    if (! fp ) exit ( -1);
    fseek ( fp , offset * sizeof (int) , SEEK_SET );
    fwrite (&x, sizeof (int), 1, fp);
    fclose(fp);
    
    return 0;
}
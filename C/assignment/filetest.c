#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *myfile=fopen("good.txt","w");
    fprintf(myfile,"HELLO WORLD OF FILES");
    fclose(myfile);
}

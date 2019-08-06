#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *myfile=fopen("Sizetest.txt","w");
    fprintf(myfile,"%s\n%s\n%s\n%s","hello","how","are","you?");
    fclose(myfile);
    myfile=fopen("Sizetest.txt","r");
    printf("The contents of the file are:-");
    char c[100];
    int i;
    i=0;
    do{
        if(i==0)
            fscanf(myfile,"%s",c);
            else
                fscanf(myfile,"\n%s",c);
        printf("\n%s",c);
        i++;
}while(getc(myfile)!=EOF);
fclose(myfile);
            }


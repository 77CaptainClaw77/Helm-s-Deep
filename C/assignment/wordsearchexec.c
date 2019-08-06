#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("Enter in the format: ExecutableFileName filename string");
        return 0;
    }
    char ch[100];
    printf("%s",argv[0]);
    FILE *myfile=NULL;
    myfile=fopen(argv[1],"r");
    if(myfile==NULL){

    }
}

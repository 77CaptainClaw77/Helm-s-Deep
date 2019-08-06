#include <stdio.h>
#include <stdlib.h>
#define FILERR if(myfile==NULL){\
        printf("Error in opening or creating a new file");\
        exit(5);\
    }
int main(){
    int i=1;
    FILE *myfile=NULL;
    myfile=fopen("alphabet.txt","w");
    char ch='a';
    FILERR;
    for(ch='a';ch<='z';ch++){
        putc(ch,myfile);
    }
    printf("The alphabet has been entered\n");
    fclose(myfile);
    myfile=fopen("alphabet.txt","r");
    FILERR;
    while(i>0)
    {
        ch=fgetc(myfile);
        if(ch==EOF)
            break;
        printf("%c\t",ch);
    }
    fclose(myfile);
    return 0;
}

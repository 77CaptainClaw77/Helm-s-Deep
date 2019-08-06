#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int no;
    char str[20];
    float floatno;
}randomstruc;
void main(){
    int size;
    randomstruc ran;
    size=0;
    char c;
    FILE *myfile=fopen("sizeoffile.txt","w");
    printf("Enter file content");
    scanf("%d %s %f",&ran.no,ran.str,&ran.floatno);
    fprintf(myfile,"%d %s %f",ran.no,ran.str,ran.floatno);
    fclose(myfile);
    myfile=fopen("sizeoffile.txt","r");
    for(;;){
        c=getc(myfile);
        if(c==EOF)
            break;
        else
            size++;
    }
    printf("%d",size);
 }

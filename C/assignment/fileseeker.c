#include<stdio.h>
#include<stdlib.h>
void main(){
    FILE *myfile=fopen("Power.txt","w");
    fprintf(myfile,"HELOO HOLA");
    fclose(myfile);
    myfile=fopen("Power.txt","r");
    fseek(myfile,1,SEEK_CUR);
    char ch=fgetc(myfile);
    printf("%c",ch);
    rewind(myfile);
    ch=fgetc(myfile);
    printf("%c",ch);
    fclose(myfile);
}

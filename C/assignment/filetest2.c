#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  main()
{
    int i=1;
    char s1[20];
    char s2[20];
    char eu[20];
    char ep[20];
    FILE *myfile=NULL;
    myfile=fopen("MyTextFile.txt","w");
    if(myfile==NULL){
        printf("Error in opening or creating a new file");
        exit(5);
    }
    printf("Enter an Username");
    scanf("%s",s1);
    printf("Enter a Password");
    scanf("%s",s2);
    fprintf(myfile,"%s %s ",s1,s2);
    fclose(myfile);
    myfile=fopen("MyTextFile.txt","r");
    if(myfile==NULL){
        printf("Error in opening or creating a new file");
        exit(5);
    }
    while(fscanf(myfile,"%s %s",s1,s2)!=EOF && i!=0){
        fflush(stdin);
        printf("\nEnter your username:");
        scanf("%s",eu);
        printf("\nEnter your password:");
        scanf("%s",ep);
        if(strcmp(s1,eu)==0 && strcmp(s2,ep)==0)
        {
            i=0;
            printf("\nLOGIN SUCCESSFUL");
        }
        else
        {

            printf("\nUsername or password is wrong, please try again...\n");
        }
    }
    fclose(myfile);
   return 0;
}

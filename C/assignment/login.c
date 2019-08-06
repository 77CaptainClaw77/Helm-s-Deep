#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int main(){
printf("Do you have an account?");
printf("\nIf yes, press y");
char ch=getchar();
char username[10];
char password[10];
char user_entered[10];
char pass_entered[10];
FILE *user=fopen("USERNAME.txt","a+");
FILE *pass=fopen("PASSWORD.txt","a+");
int i=0;
if(ch=='y')
{
retry:i=0;
     fflush(stdin);
    printf("\nEnter username and password");
    printf("\nUsername:");
    gets(user_entered);
    printf("\nPassword:");
    gets(pass_entered);
    fscanf(user,"%s",username);
    fscanf(pass,"%s",password);
    if(strcmp(user_entered,username)==0)
        i++;
    if(strcmp(pass_entered,password)==0)
        i++;
    if(i==2){
        printf("\nLOGIN SUCCESSFUL.");
    }
    else
    {
        printf("The username or password is incorrect. Please try again.\n");
        goto retry;
    }
}
else{
    fflush(stdin);
    printf("Enter a new username:");
    gets(username);
    printf("Enter a new password:");
    gets(password);
    fprintf(user,username);
    fscanf(user,"%s",username);
    fprintf(pass,password);
    fscanf(pass,"%s",password);
    printf("%s",username);
    puts(password);

    printf("\nThank you for creating a new account. Now reopen the program to login");
}
fclose(pass);
fclose(user);
return 0;
}
*/
int main(){
    printf("Enter a username and password");
    FILE *user=fopen("USERNAME.txt","w");
    FILE *pass=fopen("PASSWORD.txt","w");
    char username[10];
    char password[10];
    fflush(stdin);
    gets(username);
    gets(password);
    fprintf(user,username);
    fprintf(pass,password);
    fclose(user);
    fclose(pass);
    user=fopen("USERNAME.txt","r");
    pass=fopen("PASSWORD.txt","r");
    fflush(stdin);
    fscanf(user,"%s",username);
    fscanf(pass,"%s",password);
    fclose(user);
    fclose(pass);
    puts(username);
    puts(password);
}

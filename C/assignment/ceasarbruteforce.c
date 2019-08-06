#include <stdio.h>
#include <string.h>
#include <math.h>
char code[100];
char message[100];
char message_set[26][100];
void encryption();
void decryption();
void main(){
    int len;
    int i;
    int choice;
there:printf("Select an option\n1.)Encryption\n2.)Decryption\n");
    scanf("%d",&choice);
    if(choice==1)
        encryption();
    else if(choice==2)
        decryption();
    else{
        printf("\nPlease enter a valid option:");
        goto there;
    }

}
void decryption(){
    char junk=getchar();
    printf("Enter the coded message\n");
    gets(code);
    tolower(code);
    printf("If you know the shift press 1. Press any other number to brute force through all the possible values of shift");
    int c,i;
    int shift;
    scanf("%d",&c);
    if(c==1){
        printf("\nEnter the shift");
        scanf("%d",&shift);
        for(i=0;code[i]!='\0';i++){
            message[i]=((code[i]-'a'-shift+26)%26)+'a';
        }
                printf("The decoded message is :");
        puts(message);
    }
    else{
            for(shift=1;shift<27;shift++){
                for(i=0;code[i]!='\0';i++){
            message[i]=((code[i]-'a'-shift+26)%26)+'a';
            }
            printf("Pass %d:",shift);
            puts(message);
            strcpy(message_set[shift-1],message);

    }


}
}
void encryption(){
    char junk=getchar();
    printf("Enter the message");
    gets(message);
    printf("Enter a shift value or press 0 to randomize the shift value");
    int shift,i;
    scanf("%d",&shift);
    if(shift==0){
        shift=(rand()%27)+1;
    }
        for(i=0;message[i]!='\0';i++){
            code[i]=((message[i]-'a'+shift)%26)+'a';
        }
        printf("The coded message is :");
        puts(code);
        printf("With a shift value of %d",shift);
}


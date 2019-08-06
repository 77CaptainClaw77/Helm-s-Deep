#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void TOH(int n,char from,char to,char aux){
    if(n==1){
        printf("\nMove disk 1 from %c rod to %c rod",from,to);
        return;
    }
    TOH(n-1,from,aux,to);
    printf("\nMove disk %d from %c rod to %c rod",n,from,to);
    TOH(n-1,aux,to,from);
}
int main(){
    printf("Enter the number of discs");
    int n;
    scanf("%d",&n);
    if(pow(2,n)>500){
        printf("The operation you are requesting will produce 500 or more lines of output, please enter a smaller value.");
        exit(0);
    }
    printf("Enter the rod on which the disks are placed, auxillary rod and destination rod");
    char from,to,aux;
    fflush(stdin);
    scanf("%c %c %c",&from,&aux,&to);
    TOH(n,from,to,aux);
    return 0;
}

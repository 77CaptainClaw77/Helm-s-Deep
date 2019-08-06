#include<stdio.h>
#include <stdlib.h>
struct QUEUE{
  int FRONT;
  int REAR;
  int ele[100];
}Q;
void insertion(){
int ele;
int ch=0;
do{
    printf("Enter element to be inserted into the queue\n");
scanf("%d",&ele);
Q.ele[Q.REAR]=ele;
if(Q.REAR==100){
    printf("Queue is full\n");
    break;
}
Q.REAR++;
printf("Enter 1 to exit, enter any other key to continue\n");
scanf("%d",&ch);
}while(ch!=1);
}
void deletion(){
int ch=0;
do{
    if(Q.FRONT==Q.REAR)
    {
        printf("Queue is empty\n");
        break;
    }
    printf("%d was deleted\n",Q.ele[Q.FRONT]);
    Q.FRONT++;
    printf("Enter 1 to exit, press any other key to continue deletion\n");
    scanf("%d",&ch);
}while(ch!=1);
}
void display(){
    int i=0;
    if(Q.FRONT==Q.REAR)
        printf("No elements to display\n");
    else
        for(i=Q.FRONT;i<Q.REAR;i++)
            printf("\n%d",Q.ele[i]);
}
int main(){
    Q.FRONT=0;
    Q.REAR=0;
    int ch;
    ch=0;
    printf("\nSelect the desired option. Invalid option will lead to exiting the program");
    do{
            printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
            scanf("%d",&ch);
            switch(ch){
        case 1:insertion();
        break;
        case 2:deletion();
        break;
        case 3:display();
        break;
            }

    }while(ch!=4);
    return 0;
}

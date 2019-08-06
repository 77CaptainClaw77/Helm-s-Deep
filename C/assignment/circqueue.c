#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct QUEUE{
    int element;
};
struct QUEUE Q[MAX];
int f=0;
int r=0;
int isfull(){
    if((r==MAX-1 && f==0) || (r==f-1 && f>0))
        return 1;
    return 0;
}
int isempty(){
    if(f==r)
        return 1;
    return 0;
}
void insert(){
    int ele;
    int flag;
    do{
        if(isfull()==1){
            printf("The queue is full");
            return;
        }
        printf("\nEnter the element to be inserted");
        scanf("%d",&ele);
        Q[r].element=ele;
        r=(r+1)%MAX;
        printf("Enter 1 to continue, press anything else to exit");
        scanf("%d",&flag);
        if(flag!=1)
            break;
    }while(1);
    return;
}
void deletion(){
    int flag;
    do{
        if(isempty()==1){
            printf("The queue is empty");
            return;
        }
        printf("\n%d was deleted",Q[f].element);
        f=(f+1)%MAX;
        printf("Enter 1 to continue, press anything else to exit");
        scanf("%d",&flag);
        if(flag!=1)
            break;
    }while(1)
;    return;
}
void display(){
    int i;
    if(isempty()==1)
        printf("\nQueue is empty");
    else
    {

        for(i=f;i!=r;i=(i+1)%MAX)
            printf("\n%d",Q[i].element);
    }
}
void  main(){
	//int i;
	int choice;
	do{
	printf("\nSelect your desired option");
	printf("\n1.Insert an element\n2.Delete an element\n3.Display\n4.Exit");
	scanf("%d",&choice);
	switch(choice){
    case 1:insert();
        break;
    case 2:deletion();
        break;
    case 3:display();
        break;
    case 4:exit(EXIT_SUCCESS);
    default:printf("\nEnter a valid option");
	}
	}while(1);

}

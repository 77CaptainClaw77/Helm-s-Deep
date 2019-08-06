#include <stdio.h>
#include <stdlib.h>
#define MAX 3
struct CircularQueue{
    int element;
};
int front;
int rear;
struct CircularQueue Q[MAX];
int isfull(){
    if((rear==MAX-1 && front==0) || (rear==front-1){
        printf("Queue is full!");
        return 1;
    }
    return 0;
}
int isempty(){

    if(rear==front){
        printf("Queue is empty");
        return 1;
    }

    return 0;
}
void insert(){
    int value;
    do{
        if(isfull())
            return;
        printf("Enter a new value");
        scanf("%d",&value);
        Q[rear].element=value;
        rear=(rear+1)%MAX;
    printf("Press 1 to continue, press anything else to return");
    int ch;
    scanf("%d",&ch);
    if(ch!=1)
        break;
    }while(1);
}
void deletion(){
    int value;
    do{
        if(isempty())
            return;
        value=Q[front].element;
        printf("%d was deleted",value);
        front=(front+1)%MAX;
        printf("Press 1 to continue, press anything else to return");
    int ch;
    scanf("%d",&ch);
    if(ch!=1)
        break;
    }while(1);

}

int main()
{
    int i;
    front=0;
    rear=0;
    do{
          printf("Enter your choice\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:insert();
            break;
            case 2:deletion();
            break;
            case 3:i=front;
            for(;i!=rear;i=(i+1)%MAX)
                printf("%d",Q[i].element);
            break;
            case 4:exit(0);
            default:printf("Enter a valid choice");
        }
    }while(1);
	return 0;
}

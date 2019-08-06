#include <stdio.h>
#include <stdlib.h>
#define N
struct node{
    int priority;
    char task[100];
    struct node *next;
};
typedef struct node* NODE;
NODE insertion(NODE list)
{
    NODE newn=(NODE)malloc(sizeof(NODE));
    if(newn==NULL){
        printf("\nNo memory for new task");
        return list;
    }
    printf("\nEnter task name");
    scanf("%s",newn->task);
    printf("\nEnter the priority of the task");
    scanf("%d",&newn->priority);
    newn->next=NULL;
    if(list==NULL)
        return newn;
    NODE temp=list;
    NODE prev=NULL;
    while(temp!=NULL && newn->priority>=temp->priority){
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        newn->next=list;
        list=newn;
        return list;
    }
    if(temp==NULL)
    {
        prev->next=newn;
        return list;
    }
    prev->next=newn;
    newn->next=temp;
    return list;
}
NODE deletion(NODE list)
{
    if(list==NULL)
    {
        printf("No pending tasks");
        return list;
    }
    NODE temp=list;
    printf("%s was completed",temp->task);
        list=list->next;
        free(temp);
        return list;

}
void display(NODE list)
{
    NODE temp;
    temp=list;
    if(list==NULL)
    {
        printf("No pending tasks");
        return;
    }
    printf("\nThe tasks are \n");
    while(temp!=NULL){
        printf("%s\t",temp->task);
        temp=temp->next;
    }
    return;
}
void  main(){
    NODE list=NULL;
	//int i;
	int choice;
	do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        scanf("%d",&choice);
        switch(choice){
        case 1:list=insertion(list);
            break;
        case 2:list=deletion(list);
            break;
        case 3:display(list);
            break;
        case 4:exit(0);
            break;
        default:printf("Invalid Option");
        }
	}while(1);
}

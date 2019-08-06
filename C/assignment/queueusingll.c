#include <stdio.h>
#include <stdlib.h>
#define N
struct node{
    int value;
    struct node *next;
};
typedef struct node* NODE;
NODE insertion(NODE list)
{
    int value;
    NODE newn=NULL;
    newn=(NODE)malloc(sizeof(NODE));
    if(newn==NULL)
    {
        printf("\nQueue is full, memory allocation failed.");
        return list;
    }
    printf("Enter the value of the new node");
    scanf("%d",&value);
    newn->value=value;
    newn->next=NULL;
    if(list==NULL){
        list=newn;
        return list;
    }
    NODE temp=NULL;
    temp=list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;
    return list;
}
NODE deletion(NODE list)
{
    if(list==NULL)
    {
        printf("Queue is empty");
        return list;
    }
    NODE temp=list;
    printf("%d was deleted",temp->value);
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
        printf("Queue is empty");
        return;
    }
    printf("\nThe queue elements are \n");
    while(temp!=NULL){
        printf("%d\t",temp->value);
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

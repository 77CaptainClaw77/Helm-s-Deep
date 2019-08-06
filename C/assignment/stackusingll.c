#include <stdio.h>
#include <stdlib.h>
#define N 1
struct node{
    int value;
    struct node *next;
};
typedef struct node* NODE;
NODE push(NODE list){
    int val;
    NODE newnode=(NODE)malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("\nOverflow condition encountered...");
        return list;
    }
    printf("Enter the value to be pushed into the stack");
    scanf("%d",&val);
    newnode->value=val;
    newnode->next=NULL;
    if(list==NULL){
        list=newnode;
        return list;
    }
    /*if(list->next==NULL){
        list->next=newnode;
        return list;
    }*/
    NODE temp=NULL;
    NODE prev=NULL;
    temp=list;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    temp->next=newnode;
    return list;
}
NODE pop(NODE list)
{
    if(list==NULL){
        printf("\nUnderflow condition encountered...");
        return list;
    }
    if(list->next==NULL){
        list=NULL;
        return list;
    }
     NODE temp=NULL;
    NODE prev=NULL;
    temp=list;
     while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return list;
}
void display(NODE list){
    if(list==NULL)
    {
        printf("List is empty");
        return;
    }
    NODE temp=NULL;
    temp=list;
    while(temp!=NULL){
        printf("%d\t",temp->value);
        temp=temp->next;
    }
}
int main(){
	int i;
	NODE list;
	list=NULL;
	//char ch;
	int choice;
	do{
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        scanf("%d",&choice);
        switch(choice){
        case 1:list=push(list);
            break;
        case 2:list=pop(list);
            break;
        case 3:display(list);
            break;
        case 4:exit(0);
            break;
        default:printf("Invalid Option");
        }
	}while(1);
	return 0;
}

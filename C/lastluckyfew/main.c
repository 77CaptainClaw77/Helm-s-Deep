#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
typedef struct node* Node;
Node insertion(int pos,Node start)
{
    printf("\nEnter  the value of the new node");
    int value;
    scanf("%d",&value);
    Node temp=start;
    Node prev;
    Node newnode=(Node)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("\nMem Alloc Error");
        return start;
    }
    newnode->next=NULL;
    newnode->value=value;
    if(pos==-1){
        if(start==NULL)
            return newnode;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        return start;
    }
    if(start==NULL && pos==1)
        return newnode;
    int count=1;
    while(temp!=NULL && count!=pos){
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(temp==NULL && count==pos)
        prev->next=newnode;
    else if(temp==NULL)
        printf("Insertion out of bounds");
    else
    {
        prev->next=newnode;
        newnode->next=temp;
    }
    return start;
}
Node deletion(Node start)
{
    if(start==NULL)
    {
        printf("\nList is empty\n");
        return NULL;
    }
    Node temp=start;
    start=start->next;
    printf("\n%d was deleted",temp->value);
    free(temp);
    return start;
}
Node reversal(Node start){
    if(start==NULL || start->next==NULL)
        return start;
    Node temp=start->next;
    Node prev;
    start->next=NULL;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        prev->next=start;
        start=prev;
    }
    return start;
}
void display(Node start){
    if(start==NULL)
        printf("List is empty");
    else{
        Node temp=start;
        while(temp!=NULL)
        {
            printf("%d\t",temp->value);
            temp=temp->next;
        }
    }
}
void main()
{
    int choice;
    Node list=NULL;
    while(1){
        printf("\nSelect your desired operation:-\n");
        printf("1.Insert\n2.Delete\n3.Reverse List\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:printf("\nTo insert at a specified position press 1 else press any other number");
            scanf("%d",&choice);
            if(choice==1){
                printf("\nEnter the position of insertion");
                scanf("%d",&choice);
                if(choice<1)
                    printf("\nInvalid Position");
                else
                    list=insertion(choice,list);
            }
            else
                list=insertion(-1,list);
            break;
        case 2:list=deletion(list);
            break;
        case 3:list=reversal(list);
            break;
        case 4:display(list);
            break;
        case 5:exit(0);
            break;
        default:printf("Invalid choice");

        }
    }
}

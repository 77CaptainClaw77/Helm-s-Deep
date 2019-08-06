#include <stdio.h>
struct node{
    int value;
    struct node *next;
};
typedef struct node* Node;
Node insertion(Node start,int value)//Sorted inserted
{
    Node newnode=(Node)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("\nMem alloc error");
        return start;
    }
    newnode->value=value;
    newnode->next=NULL;
    if(start==NULL)
        return newnode;
    Node temp=start;
    Node prev=NULL;
    while(temp!=NULL && temp->value>value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        prev->next=newnode;
        return start;
    }
    if(prev==NULL){
        newnode->next=start;
        start=newnode;
        return start;
    }
    prev->next=newnode;
    newnode->next=temp;
    return start;
}
int search(Node start,int value){
    Node temp=start;
    while(temp!=NULL){
        if(temp->value==value)
            return 1;
        temp=temp->next;
    }
    return 0;
}
Node Union(Node start,Node l1,Node l2){
    Node tempb,tempc;
    tempb=l1;
    tempc=l2;
    while(tempb!=NULL){
        if(search(start,tempb->value)==0)
        {
            start=insertion(start,tempb->value);
        }
        tempb=tempb->next;
    }
    while(tempc!=NULL){
        if(search(start,tempc->value)==0)
        {
            start=insertion(start,tempc->value);
        }
        tempc=tempc->next;
    }
    return start;
}
Node Intersection(Node start,Node l1,Node l2){
    Node tempb,tempc;
    //tempa=start;
    tempb=l1;
    tempc=l2;
    while(tempc!=NULL){
        if(search(tempb,tempc->value)==1)
        {
            start=insertion(start,tempc->value);
        }
        tempc=tempc->next;
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
void main(){
    int value;
    Node l1,l2,l3,l4;
    l1=NULL;
    l2=NULL;
    l3=NULL;
    l4=NULL;
    int choice;
    do{
        printf("\nSelect your desired operation:-\n");
        printf("1.Insert into list 1\n2.Insert into list 2\n3.Union\n4.Intersection\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("\nEnter the value of the node");
    scanf("%d",&value);
            l1=insertion(l1,value);
            break;
        case 2:printf("\nEnter the value of the node");
    scanf("%d",&value);
            l2=insertion(l2,value);
            break;
        case 3:l3=Union(l3,l2,l1);
            break;
        case 4:l4=Intersection(l4,l2,l1);
            break;
        case 5:printf("\nList 1\n");
            display(l1);
            printf("\nList 2\n");
            display(l2);
            printf("\nUnion\n");
            display(l3);
            printf("\nIntersection\n");
            display(l4);
            break;
        case 6:exit(0);
            break;
        default:printf("\nInvalid Choice");
            break;
        }

    }while(1);
}

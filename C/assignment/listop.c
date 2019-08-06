#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
typedef struct node *NODE;
NODE insertion(NODE list,int pos){
    int value;
    NODE newn=(NODE)malloc(sizeof(NODE));
    if(newn==NULL){
        printf("Memory Allocation error...");
        return list;
    }
    else{
        printf("enter the value of the new node");
        scanf("%d",&value);
        newn->next=NULL;
        newn->value=value;
        if(pos==-3){//Insertion at start.
           if(list==NULL){
                list=newn;
                return list;
           }
           newn->next=list;
           list=newn;
            return list;
        }
        else if(pos==-2){//Insertion at end.
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
        else{//insertion at specified position
             if(list==NULL && pos==0){
                list=newn;
                return list;
           }
           NODE temp=list;
           NODE prev;
           int count=0;
           while(temp!=NULL && count<pos)
           {
               prev=temp;
               temp=temp->next;
               count++;
           }
           if(count==pos && temp==NULL){
                temp=newn;
                prev->next=temp;
                return list;
           }
           else if(count==pos && temp!=NULL)
           {
               prev->next=newn;
               newn->next=temp;
               return list;
           }
           else{
            printf("Invalid postion");
            return list;
           }

        }
    }
}
NODE deletion(NODE list,int pos){
     int value;
    NODE temp;
    NODE prev;
    //else{
       // printf("enter the value of the new node");
        //scanf("%d",&value);
        //newn->next=NULL;
        //newn->value=value;
        if(pos==-3){//Deletion at start.
           if(list==NULL){
                printf("List is empty");
                return list;
           }
           //newn->next=list;
           temp=list;
           list=list->next;
           free(temp);
            return list;
        }
        else if(pos==-2){//Deletion at end.
           if(list==NULL){
                printf("List is empty");
                return list;
           }
           //NODE temp=NULL;
           temp=list;
           if(list->next==NULL)
           {
               list=NULL;
               free(temp);
               return list;
           }
           while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
            }
            prev->next=NULL;
            free(temp);
            return list;
        }
        else{//deletion at specified position
             if(list==NULL){
                printf("List is empty");
                return list;
           }
           NODE temp=list;
           NODE prev;
           int count=0;
           while(temp!=NULL && count<pos)
           {
               prev=temp;
               temp=temp->next;
               count++;
           }
           if(count==pos && temp==NULL){
                printf("Invalid position");
                return list;
           }
           else if(count==pos && temp!=NULL)
           {
               prev->next=temp->next;
               free(temp);
               return list;
           }
           else{
            printf("Invalid position");
            return list;
           }

        }
    //}

}
NODE reversal(NODE list){
    NODE prev,temp;
    NODE ls;
    if(list==NULL || list->next==NULL)
        return list;
    ls=list;
    temp=list->next;
    while(temp!=NULL){
        prev=temp;
        temp=temp->next;
        prev->next=list;
        list=prev;
    }
    ls->next=NULL;
    return list;
}
void display(NODE list){
    NODE temp;
    temp=list;
    if(list==NULL)
    {
        printf("List is empty");
        return;
    }
    printf("\nThe list elements are \n");
    while(temp!=NULL){
        printf("%d\t",temp->value);
        temp=temp->next;
    }
    return;
}
void main(){
    int choice,ch;
    NODE list=NULL;
    do{
        printf("1.Insert\n2.Delete\n3.Reverse List\n4.Display\n5.Exit");
        scanf("%d",&choice);
        switch(choice){
    case 1:printf("1.Insert at start\n2.Insert at end\n3.Insert at specified position");
            scanf("%d",&ch);
            switch(ch){
                case 1:list=insertion(list,-3);
                break;
                case 2:list=insertion(list,-2);
                break;
                case 3:printf("\nEnter the position of insertion");
                scanf("%d",&ch);
                list=insertion(list,ch);
                break;
                default:printf("\nInvalid input");
            }
        break;
    case 2:printf("1.Delete at start\n2.Delete at end\n3.Delete at specified position");
            scanf("%d",&ch);
            switch(ch){
                case 1:list=deletion(list,-3);
                break;
                case 2:list=deletion(list,-2);
                break;
                case 3:printf("\nEnter the position of deletion");
                scanf("%d",&ch);
                list=deletion(list,ch);
                break;
                default:printf("\nInvalid input");
            }
        break;
    case 3:list=reversal(list);
        break;
    case 4:display(list);
        break;
    case 5:exit(0);
    default:printf("\nInvalid choice");
        }
    }while(1);
}

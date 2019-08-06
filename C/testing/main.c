#include<stdio.h>

#include<stdlib.h>

typedef struct node

{

int info;

struct node *lptr,*rptr;

}NODE;

void ins_right(NODE *head,int data)

{

int key;

NODE *newnode,*temp;

newnode=(NODE*)malloc(sizeof(NODE));

newnode->info=data;

if(head->rptr==NULL)

{

head->rptr=newnode;

newnode->lptr=head;

newnode->rptr=NULL;

head->info++;

printf("\n%d is inserted into list",data);

}

else

{

printf("\nEnter the key element: ");

scanf("%d",&key);

temp=head->rptr;

while(temp!=NULL && temp->info!=key)

temp=temp->rptr;

if(temp==NULL)

printf("\nKey %d is not found in list",key);

else

{

newnode->rptr=temp->rptr;

if(temp->rptr!=NULL)

temp->rptr->lptr=newnode;

temp->rptr=newnode;
newnode->lptr=temp;

head->info++;

printf("\n%d is inserted to the right of key %d",data,key);

}

}

}

void del_first(NODE *head,NODE *temp)

{

while(temp->lptr!=head)

temp=temp->lptr;

head->rptr=temp->rptr;

if(temp->rptr!=NULL)

temp->rptr->lptr=head;

head->info--;

printf("\nFirst node with data %d is deleted from list",temp->info); free(temp);

}

void swap_data(NODE *head,int m,int n)

{

NODE *p1,*p2;

int i,temp;

if((m<1 || m > head->info) || (n<1 || n > head->info)) printf("\nInvalid node numbers for swapping !!!");

else

{

for(i=1,p1=head->rptr;i!=m;i++,p1=p1->rptr);

for(i=1,p2=head->rptr;i!=n;i++,p2=p2->rptr);

temp=p1->info;

p1->info=p2->info;

p2->info=temp;

printf("\nSwapped the data of nodes %d and %d",m,n);

}

}

void display(NODE *head)

{

NODE *temp;

if(head->rptr==NULL)

printf("\nEMPTY LIST");

else

{

temp=head->rptr;

printf("\nLIST CONTENTS:\nBegin<->");
while(temp!=NULL)

{

printf("%d<->",temp->info);

temp=temp->rptr;

}

printf("End");

printf("\nTotal number of nodes = %d",head->info);

}

}

int main()

{

NODE *head,*temp;

int choice,m,n,data;

head=(NODE*)malloc(sizeof(NODE));

head->info=0;

head->lptr=head->rptr=NULL;

while(1)

{

printf("\n1:Ins_right 2:Del_first 3:Swap 4:Display 5:Exit"); printf("\nEnter your choice: ");
scanf("%d",&choice);

switch(choice)

{

case 1: printf("\nEnter the data: ");

scanf("%d",&data);

ins_right(head,data);

break;

case 2:  if(head->rptr==NULL)

printf("\nEMPTY LIST");

else

{

temp=head->rptr;

while(temp->rptr!=NULL)

temp=temp->rptr;

del_first(head,temp);

}

break;

case 3:  if(head->rptr==NULL)

printf("\nEMPTY LIST");

else

{

printf("\nEnter the values of m and n: ");

scanf("%d%d",&m,&n);

swap_data(head,m,n);
}

break;

case 4:  display(head);

break;

case 5:  exit(0);

default: printf("\nINVALID CHOICE !!!");

}

}

return 0;

}

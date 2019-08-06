#include <stdio.h>
#include <stdlib.h>
#define N 1
struct node{
    int value;
    struct node *next;
};
typedef struct node* NODE;
 NODE insert(NODE list){
    NODE newnode=(NODE)malloc(sizeof(NODE));
    if(newnode==NULL){
        printf("Linked list is full, Cannot insert any more elements");
        return list;
    }
    printf("Enter the value of the new node");
    if(list==NULL)
 }
void  main(){
    int choice;
    do{
    printf("1.Insert into list1\n2.Insert into list2\n3.Delete from list1\n4.Delete from list2\n5.Display list1\n6.Display list2\n7.Display Union\n8.Display Instersection\n9.Exit\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
    case 2:
    case 3:
    case 4:
    default:
    }
    }while(1);
	int i;
}

#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};
struct node* is_palin(){
    printf("Enter the number of elements: ");
    int n,i,c;
    c=0;
    scanf("%d",&n);
    int arr[n];
    if(n==0) return NULL;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    printf("Enter the elements: \n");
    scanf("%d",&head->data); // -> has higher preference
    arr[c++]=head->data;
    for(i=1;i<n;i++){
        struct node* newn=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newn->data);
        temp->next=newn;
        temp=temp->next;
	arr[c++]=temp->data;
    }
    temp->next=NULL;
    int pal=1;
    for(i=0;i<c/2;i++){
      if(arr[i]!=arr[c-i-1]){
	pal=0;
      }
    }
    printf("%s",pal==0?"Not a Palindrome":"Palindrome");
    return head;
}
int main(){
  is_palin();
  return 0;
}

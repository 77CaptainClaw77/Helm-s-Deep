#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node{
    int data;
    struct node* next;
};
struct node* read_data(){
    printf("Enter the number of elements: ");
    int n,i;
    scanf("%d",&n);
    if(n==0) return NULL;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    printf("Enter the elements: \n");
    scanf("%d",&head->data); // -> has higher preference
    for(i=1;i<n;i++){
        struct node* newn=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newn->data);
        temp->next=newn;
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
void print_list(struct node* head){
    printf("\nThe elements of the linked list are:- ");
    struct node* temp=head;
    for(;temp;temp=temp->next)
        printf("%d ",temp->data);
}
int sum_list(struct node* head){
    int s=0;
    struct node* temp=head;
    for(;temp;temp=temp->next)
        s+=temp->data;
    return s;
}
struct node* delete_nodes_by_value(struct node* head,int val){
    struct node*temp=head;
    for(;temp && temp->next;temp=temp->next){ //delete all except first node
        while(temp->next && temp->next->data==val){
            struct node* del=temp->next;
            temp->next=temp->next->next;
            free(del);
        }
    }
    if(head->data==val){ //check first node
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}
struct node* remove_duplicates_sorted(struct node* head){
    struct node* temp;
    temp=head;
    for(;temp && temp->next;temp=temp->next){
        while(temp->next && temp->data==temp->next->data){
            struct node* del=temp->next;
            temp->next=temp->next->next;
            free(del);
        }
    }
    return head;
}
struct node* reverse_list(struct node* head){
    int sz=10;
    int* arr=(int*)malloc(sizeof(int)*sz);
    int i=0,j=0;
    struct node* temp=head;
    for(;temp;temp=temp->next){
        if(i==sz){
            sz*=2;
            arr=realloc(arr,sizeof(int)*sz);
        }
        arr[i++]=temp->data;
    }
    temp=head;
    for(;j<i;j++){
        temp->data=arr[i-j-1];
        temp=temp->next;
    }
    return head;
}
void find_max_min(struct node* head,int arr[]){
    int max_ele=INT_MIN,min_ele=INT_MAX;
    struct node* temp=head;
    for(;temp;temp=temp->next){
        max_ele=max_ele<temp->data?temp->data:max_ele;
        min_ele=min_ele>temp->data?temp->data:min_ele;
    }
    arr[0]=max_ele;
    arr[1]=min_ele;
}
int main()
{
    struct node* head=read_data(); //read
    print_list(head); //print
    printf("\nThe sum of the elements of the list is %d",sum_list(head));
    int mx_mn_arr[2];
    find_max_min(head,mx_mn_arr);
    printf("\nMaximim element: %d\t\tMinimum element: %d\n",mx_mn_arr[0],mx_mn_arr[1]);
    printf("Enter node value to delete by : ");
    int del_val;
    scanf("%d",&del_val);
    head=delete_nodes_by_value(head,del_val);
    print_list(head);
    printf("\n Now for sorted list operations\n");
    struct node* sorted_head=read_data();
    sorted_head=remove_duplicates_sorted(sorted_head);
    print_list(sorted_head);
    return 0;
}

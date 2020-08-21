#include <stdio.h>
#include <stdlib.h>
struct stack_using_arr{
    int top;
    int* arr;
    int sz;
};
struct stack_node{
    int data;
    struct stack_node* next;
};
struct stack_using_ll{
    int top;
    struct stack_node* head;
    int sz;
};
void create_new_sll(struct stack_using_ll* sl){
    sl->head=NULL;
    sl->top=-1;
    sl->sz=5;
}
int is_overflow_ll(struct stack_using_ll* sl){
    return sl->top==sl->sz-1;
}
int is_underflow_ll(struct stack_using_ll* sl){
    return sl->top==-1;
}
void push_ll(struct stack_using_ll* sl,int ele){
    if(!is_overflow_ll(sl)){
        struct stack_node* newn=malloc(sizeof(struct stack_node));
        newn->data=ele;
        newn->next=sl->head;
        sl->head=newn;
        sl->top++;
    }
    else
        printf("Overflow occured\n");
}
int pop_ll(struct stack_using_ll* sl){
    if(!is_underflow_ll(sl)){
        struct stack_node* temp=sl->head;
        sl->head=sl->head->next;
        int ele=temp->data;
        free(temp);
        sl->top--;
        return ele;
    }
    else{
        printf("Stack is empty!\n");
        return -1;
    }
}
int get_top_ll(struct stack_using_ll* sl){
    if(is_underflow_ll(sl)){
        printf("Stack is empty!\n");
        return -1;
    }
    return sl->head->data;
}
int peek_stack_ll(struct stack_using_ll* sl,int pos){
    int i=1;
    struct stack_node* sn=sl->head;
    while(i<pos && sn)
        sn=sn->next;
    if(sn!=NULL)
        return sn->data;
    return -1;
}
void print_sl(struct stack_using_ll* sl){
    struct stack_node* sn=sl->head;
    if(is_underflow_ll(sl)){
        printf("Stack is empty!\n");
    }
    else{
        while(sn){
            printf("%d ",sn->data);
            sn=sn->next;
        }
    }
}
void create_new_sa(struct stack_using_arr* sa){
    sa->top=-1;
    sa->sz=5;
    sa->arr=(int*)malloc(sizeof(int)*sa->sz);
};
int is_overflow_ar(struct stack_using_arr* sa){
    return sa->top==sa->sz-1;
}
int is_underflow_ar(struct stack_using_arr* sa){
    return sa->top==-1;
}
void increase_stack_size(struct stack_using_arr* sa){
    sa->sz*=2;
    sa->arr=realloc(sa->arr,sa->sz*sizeof(int));
}
void push_ar(struct stack_using_arr* sa,int ele){
    if(!is_overflow_ar(sa))
        sa->arr[++sa->top]=ele;
    else
        printf("Overflow occured\n");
}
int pop_ar(struct stack_using_arr* sa){
    if(!is_underflow_ar(sa))
        return sa->arr[sa->top--];
    else{
        printf("Underflow occured\n");
        return -1;
    }
}
int peek_stack(struct stack_using_arr* sa,int pos){
    if(pos<1 || pos>sa->top+1){
        printf("Position out of range!\n");
        return -1;
    }
    return sa->arr[sa->top-pos+1];
}
int get_top(struct stack_using_arr* sa){
    if(is_underflow_ar(sa)){
        printf("Stack is empty!\n");
        return -1;
    }
    return sa->arr[sa->top];
}
void print_sa(struct stack_using_arr* sa){
    int i;
    for(i=1;i<=sa->top+1;i++)
        printf("%d ",peek_stack(sa,i));
}
int main(){
    struct stack_using_arr* sa=(struct stack_using_arr*)malloc(sizeof(struct stack_using_arr));
    struct stack_using_ll* sl=(struct stack_using_ll*)malloc(sizeof(struct stack_using_ll));
    create_new_sll(sl);
    create_new_sa(sa);
    int ch,ele;
//    while(1){
//        printf("1.Push\n2.Pop\n3.Peek\n4.Print\n5.Exit\n");
//        scanf("%d",&ch);
//        switch(ch){
//            case 1: scanf("%d",&ele);
//            push_ar(sa,ele);
//            break;
//            case 2: ele=pop_ar(sa);
//            printf("%d\n",ele);
//            break;
//            case 3: scanf("%d",&ele);
//            printf("%d\n",peek_stack(sa,ele));
//            break;
//            case 4: print_sa(sa);
//            break;
//            case 5: exit(0);
//        }
//    }
    while(1){
        printf("1.Push\n2.Pop\n3.Peek\n4.Print\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&ele);
            push_ll(sl,ele);
            break;
            case 2: ele=pop_ll(sl);
            printf("%d\n",ele);
            break;
            case 3: scanf("%d",&ele);
            printf("%d\n",peek_stack_ll(sl,ele));
            break;
            case 4: print_sl(sl);
            break;
            case 5: exit(0);
        }
    }
}

#include<stdio.h>
#include<stdlib.h>
int linsearch(int key,int a[100],int n){
    if(n>=0){
    if(a[n]==key){
        return n;
    }
    else{
        return linsearch(key,a,--n);
    }
    }
    return -1;

}
int main(){
    int n;
    printf("Enter the number of elements");
    scanf("%d",&n);
    int i;
    int a[n];
    printf("Enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the search element");
    int search;
    scanf("%d",&search);
    int pos=linsearch(search,a,--n);
    if(pos==-1)
        printf("The element %d does not exist in the array",search);
    else
        printf("The element %d is present at position %d",search,(pos+1));
    return 0;
}

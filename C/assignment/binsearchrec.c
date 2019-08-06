#include<stdio.h>
#include<stdlib.h>
int binsearch(int low,int high,int key,int a[100]){
    int mid=(low+high)/2;
    while(low<=high){
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            return binsearch(low,mid-1,key,a);
        else
            return binsearch(mid+1,high,key,a);
        }
        return-1;
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
    int pos=binsearch(0,n-1,search,a);
    if(pos==-1)
        printf("The element %d does not exist in the array",search);
    else
        printf("The element %d is present at position %d",search,(pos+1));
    return 0;
}


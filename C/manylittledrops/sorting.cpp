#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b){
    return a>b;
}
int main(){
    int arr[]={1,19,12,13,15};
    sort(arr,arr+5,compare);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<'\t';
    return 0;
}

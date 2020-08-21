#include <bits/stdc++.h>
using namespace std;
int get_val(int ind,int arr[]){
  int count=0;
  int i;
  for(i=0;i<201;i++){
    if(arr[i]!=0)
      count+=arr[i];
    if(count>=ind)
      break;
  }
  return i;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,d;
  int notif=0;
  cin>>n>>d;
  int expenditure[n];
  for(int i=0;i<n;i++)
    cin>>expenditure[i];
  if(d>n){
    cout<<0;
    return 0;
  }
  int counting_sort[201]={};
  float median_val=0;
  int med=d/2;
  for(int i=0;i<d;i++)
    counting_sort[expenditure[i]]++;
  for(int i=d;i<n;i++){
    if(d%2!=0){
      median_val=get_val(med,counting_sort);
    }
    else{
      median_val=(get_val(med,counting_sort)+get_val(med+1,counting_sort))/2.0;
    }
    //cout<<median_val<<endl;
    if((float)expenditure[i]>=2*median_val)
      notif++;
    counting_sort[expenditure[i-d]]--;
    counting_sort[expenditure[i]]++;
  }
  cout<<notif;
  return 0;
}

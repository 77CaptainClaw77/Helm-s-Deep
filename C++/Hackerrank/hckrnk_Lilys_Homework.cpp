#include <bits/stdc++.h>
using namespace std;
void swap_num(int& a,int& b){
  int temp=a;
  a=b;
  b=temp;
}
int sort_pivot(vector<int>& arr,int l,int r){
  int i=l-1,j=l,piv=arr[r];
  for(int k=l;k<r;k++){
    if(arr[k]<=piv){
      i++;
      if(i!=k) //avoid unnecessary swap
	swap_num(arr[i],arr[k]);
    }
  }
  swap_num(arr[i+1],arr[r]);
  return i+1;
}
void quicksort_array(vector<int>& arr,int l,int r){
  if(l<r){
    int p=sort_pivot(arr,l,r);
    quicksort_array(arr,l,p-1);
    quicksort_array(arr,p+1,r);
  }
  return;
}
int binary_search(vector<int>& arr,int ele,bool ord){
  int l=0,h=arr.size()-1;
  while(l<=h){
    int m=(l+h)/2;
    if(arr[m]==ele)
      return m;
    else if((arr[m]>ele && ord) || (arr[m]<ele && !ord))
      h=m-1;
    else
      l=m+1;
  }
  return -1;
}
int get_cycle_size(vector<int>& positions){
  int ans=0,c;
  vector<bool> visited(positions.size());
  for(int i=0;i<positions.size();i++){
    c=0;
    while(!visited[i]){
      if(positions[i]!=i)
	c++;
      visited[i]=true;
      i=positions[i];
    }
    if(c!=0)
      ans+=c-1;
  }
  return ans;
}
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  bool ord=true;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<int> sorted_arr=arr;
  quicksort_array(sorted_arr,0,n-1); //use std::sort to pass all cases.
  vector<int> positions(n);
  for(int i=0;i<n;i++)
    positions[i]=binary_search(sorted_arr,arr[i],ord);
  int cnt=get_cycle_size(positions);
  ord=false;
  for(int i=0;i<n/2;i++)
    swap_num(sorted_arr[i],sorted_arr[n-i-1]);
  for(int i=0;i<n;i++)
    positions[i]=binary_search(sorted_arr,arr[i],ord);
  cout<<min(get_cycle_size(positions),cnt);
  return 0;
}

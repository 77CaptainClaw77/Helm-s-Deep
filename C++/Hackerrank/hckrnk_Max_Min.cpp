#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int k,n;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  int min_sum=INT_MAX;
  for(int i=0;i<n-k+1;i++)
    min_sum=min(min_sum,arr[i+k-1]-arr[i]);
  cout<<min_sum;
  return 0;
}

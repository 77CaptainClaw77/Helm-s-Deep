#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n1,n2,n3,temp;
  cin>>n1>>n2>>n3;
  int arr1[n1],arr2[n2],arr3[n3];
  for(int i=0;i<n1;i++)
    cin>>arr1[i];
  for(int i=0;i<n2;i++)
    cin>>arr2[i];
  for(int i=0;i<n3;i++)
    cin>>arr3[i];
  long long sum=0;
  long long max_sum=0;
  map<long long,int> sum_count;
  for(int i=n1-1;i>=0;i--){
    sum+=arr1[i];
    sum_count[sum]++;
  }
  sum=0;
  for(int i=n2-1;i>=0;i--){
    sum+=arr2[i];
    sum_count[sum]++;
  }
  sum=0;
  for(int i=n3-1;i>=0;i--){
    sum+=arr3[i];
    sum_count[sum]++;
    if(sum_count[sum]==3 && max_sum<sum)
      max_sum=sum;
  }
  cout<<max_sum;
}

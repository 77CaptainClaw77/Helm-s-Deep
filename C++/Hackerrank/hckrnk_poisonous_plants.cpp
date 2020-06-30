#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  int *arr=new int[n];
  int* days = new int[n]();
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int min_ele=arr[0];
  stack<int> s;
  int max_day=0;
  s.push(0); //index of first element
  for(int i=1;i<n;i++){
    min_ele=min(min_ele,arr[i]);
    if(arr[i]>arr[i-1])
      days[i]=1; //will die on first day
    while(!s.empty()&& arr[i]<=arr[s.top()]){//until smaller element is encountered, continue deleting elements from the stack
      if(arr[i]>min_ele){ //plant will die
	days[i]=max(days[i],days[s.top()]+1);
      }
      s.pop();
    }
    s.push(i);
    if(max_day<days[i])
      max_day=days[i];
  }
  cout<<max_day;
  return 0;
}

#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    int p_c=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    for(int i=1;i<n-1;i++){
      if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
	p_c++;
	i++; //next cannot be a peak so skip it
      }
    }
    cout<<"Case #"<<i<<": "<<p_c<<"\n";
  }
  return 0;
}

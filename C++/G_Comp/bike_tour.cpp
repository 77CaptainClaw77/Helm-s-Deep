#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int n;
    cin>>n;
    vector<int> h_arr(n);
    for(int j=0;j<n;j++)
      cin>>h_arr[j];
    int peak_count=0;
    for(int j=1;j<n-1;j++)
      if(h_arr[j-1]<h_arr[j] && h_arr[j+1]<h_arr[j])
	peak_count++;
    cout<<"Case #"<<(i+1)<<": "<<peak_count<<endl;
  }
  return 0;
}

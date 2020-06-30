#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int N;
    cin>>N;
    if(N==0)
      cout<<"0\n";
    else{
      int check_val=1;
      int power_val=1;
      int max_represenatable=(check_val<<power_val)-1;
      while(N>max_represenatable){
	power_val++;
	max_represenatable=(check_val<<power_val)-1;
      }
      cout<<power_val<<"\n";
    }
  }
}

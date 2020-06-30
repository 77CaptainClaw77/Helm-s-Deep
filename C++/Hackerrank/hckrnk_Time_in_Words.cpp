#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  string hours[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","one"};
  string minutes[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"};
  int h,m;
  cin>>h>>m;
  if(m==0)
    cout<<hours[h-1]<<" o' clock";
  else if(m<=30){
    if(m==15)
      cout<<"quarter past "<<hours[h-1];
    else if(m==30)
      cout<<"half past "<<hours[h-1];
    else{
      if(m>1)
	cout<<minutes[m-1]<<" minutes past "<<hours[h-1];
      else
	cout<<minutes[m-1]<<" minute past "<<hours[h-1];
    }
  }
  else{
    if(m==45)
      cout<<"quarter to "<<hours[h];
    else{
      if(m<59)
	cout<<minutes[60-m-1]<<" minutes to "<<hours[h];
      else
	cout<<minutes[60-m-1]<<" minute to "<<hours[h];
     }
  }
  return 0;
}

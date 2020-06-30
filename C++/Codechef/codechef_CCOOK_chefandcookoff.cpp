#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  int n,temp,i,j;
  cin>>n;
  string arr[]={"Beginner", "Junior Developer", "Middle Developer", "Senior Developer", "Hacker", "Jeff Dean"};
  for (i = 0; i<n; ++i) {
    int points=0;
    for (j=0; j<5; ++j) {
      cin>>temp;
      points+=temp;
    }
    cout<<arr[points]<<"\n";
  }
  return 0;
}

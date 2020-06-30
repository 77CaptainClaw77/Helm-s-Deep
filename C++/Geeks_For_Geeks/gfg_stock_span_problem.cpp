#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T,N;
  cin>>T;
  while(T--){
    cin>>N;
    int arr[N];
    int span[N];
    for(int i=0;i<N;i++)
      cin>>arr[i];
    //below is stack solution, this is not necessary, offset can used to perform functions like a stack.
    // stack<int> s;
    // s.push(0);
    // span[0]=1;
    // for(int i=1;i<N;i++){
    //   while(!s.empty() && arr[i]>=arr[s.top()])
    // 	s.pop();
    //   if(s.empty())
    // 	span[i]=i+1;
    //   else
    // 	span[i]=i-s.top();
    //   s.push(i);
    // }
    span[0]=1; //first element is always 1
    for(int i=1;i<N;i++){//so span contains the offset from the element to the largest before it.
      int counter=1; //so start by checking with previous element
      while(i>=counter && arr[i]>=arr[i-counter])
	counter+=span[i-counter]; //to move to greatest element before it
      span[i]=counter;
    }
    for(int i=0;i<N;i++)
      cout<<span[i]<<" ";
    cout<<"\n";
  }
  return 0;
}

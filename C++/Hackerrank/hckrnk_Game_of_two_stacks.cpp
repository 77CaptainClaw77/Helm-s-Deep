#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int g;
  cin>>g;
  while(g--){
    int n,m,x,temp;
    cin>>n>>m>>x;
    int score=0;
    int c_val=-1;
    int arr_A[n],arr_B[m];
    for(int i=0;i<n;i++)
      cin>>arr_A[i];
    for(int i=0;i<m;i++)
      cin>>arr_B[i];
    long long sum=0;
    for(int i=0;i<n;i++){
      if(sum+arr_A[i]<=x){
	sum+=arr_A[i];
	score++;
	c_val=i;
      }
      else
	break;
    }
    int max_score=score;
    for(int i=0;i<m;i++){
      if(sum+arr_B[i]<=x){
	sum+=arr_B[i];
	score++;
	max_score=max(score,max_score);
      }
      else{
	if(c_val==-1) break;
      	sum=sum-arr_A[c_val];
	score--;
	c_val--;
	i--;
      }
      //cout<<sum<<endl;
    }
    cout<<max_score<<"\n";
  }//outer-while
  return 0;
}

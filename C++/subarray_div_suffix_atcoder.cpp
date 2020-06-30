#include <iostream>
#include <string>
#include <vector>
#define div_num 2019
using namespace std; 
int main(){
  string s;
  cin>>s;
  int n=s.size(); //size of string
  int suff=0; //suffix
  int pot=1; //power of 10
  vector<int> cnt_suff(div_num); //suffix count
  long long answer=0;
  cnt_suff[suff]++;
  for(int i=n-1;i>=0;i--){
    int dig=s[i]-'0';
    suff=(suff+dig*pot)%div_num;
    pot=pot*10%div_num;
    answer+=cnt_suff[suff];
    cnt_suff[suff]++;
  }
  cout<<answer;
}

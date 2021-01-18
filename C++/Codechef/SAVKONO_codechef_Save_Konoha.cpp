/*File Information:-
Author: Kumarguru V

Pain is the leader of a secret organization whose goal is to destroy the leaf village(Konoha). After successive failures, the leader has himself appeared for the job. Naruto is the head of the village but he is not in a condition to fight so the future of the village depends on the soldiers who have sworn to obey Naruto till death.
Naruto is a strong leader who loves his villagers more than anything but tactics is not his strong area. He is confused whether they should confront Pain or evacuate the villagers including the soldiers (he loves his villagers more than the village). Since you are his advisor and most trusted friend, Naruto wants you to take the decision. 
Pain has a strength of ZZZ and is confident that he will succeed. Naruto has NN soldiers under his command numbered 11 through NN. Power of ii-th soldier is denoted by AiA_i. When a soldier attacks pain, his strength gets reduced by the corresponding power of the soldier. However, every action has a reaction so the power of the soldier also gets halved i.e. AiA_i changes to [Ai/2][A_i/2]. Each soldier may attack any number of times (including 0). Pain is defeated if his strength is reduced to 0 or less.
Find the minimum number of times the soldiers need to attack so that the village is saved.
Link: https://www.codechef.com/problems/SAVKONO
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(int argc, char *argv[])
{
  int T,temp;
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>T;
  int N,Z;
  while(T--){
    cin>>N>>Z;
    priority_queue<int> pq;
    for(int i=0;i<N;i++){
      cin>>temp;
      pq.push(temp);
    }
    int attacks=0;
    while(Z>0){
      if(pq.empty())
	break;
      int ele=pq.top();
      if(ele==0)
	break;
      Z-=ele;
      attacks++;
      pq.pop();
      pq.push(ele/2);
    }
    if(Z>0)
      cout<<"Evacuate\n";
    else
      cout<<attacks<<"\n";
  }
  return 0;
}

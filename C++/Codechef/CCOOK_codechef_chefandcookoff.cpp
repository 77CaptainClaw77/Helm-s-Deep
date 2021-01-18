/*File Information:-
Author: Kumarguru V

Read problems statements in Mandarin chinese, Russian and Vietnamese as well.
Chef has obtained the results of a past Cook-Off. He wants to estimate the skill level of each contestant. The contestants can be classified with high probability (w.h.p.) based on the number of solved problems:


A contestant that solved exactly 0 problems is a beginner.
A contestant that solved exactly 1 problem is a junior developer.
A contestant that solved exactly 2 problems is a middle developer.
A contestant that solved exactly 3 problems is a senior developer.
A contestant that solved exactly 4 problems is a hacker.
A contestant that solved all five problems is Jeff Dean.


Please help Chef to identify the programming level of each participant.
Link: https://www.codechef.com/problems/CCOOK
*/
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

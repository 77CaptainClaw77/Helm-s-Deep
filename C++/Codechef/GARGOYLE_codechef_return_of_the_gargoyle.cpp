/*File Information:-
Author: Kumarguru V

There has been yet another murder in the Shady city of Riverdale. This murder is being investigated by none other than the Riverdale's Finest- Jughead Jones & Betty Cooper. This murder has been done exactly in the same manner as all the murders happening since the return of the deadly game Gargoyle &Griffins. Betty has decided to put an end to these murders, so they decide to interrogate each and every person in the neighbourhood.
As they don't know these people personally they want to first get to know about their character i.e whether a particular person is a Truth−speaking−personTruth−speaking−personTruth-speaking-person or a False−speaking−personFalse−speaking−personFalse-speaking-person. Jughead devises a strategy of interrogating the civilians.
Jughead decides that they will collect statements from all the people in the neighbourhood about every other person living in the neighbourhood. Each person speaks a statement in form of an array consisting of TTT and FF F, which tells us what he thinks about the ithithith person. Let there be NNN people living in the neighbourhood. So if a person iii is giving his/her statement, he/her will always call himself/herself a True person i.e Statement[i]=TStatement[i]=TStatement[i]=T.
So Jughead says that they will select the maximummaximummaximum numbernumbernumber of people that maybe speaking the truth such that their statements don't contradict and then interrogate them further about the murder.
Help them pick the max no. of Truth speaking people.
NoteNoteNote- A person speaking falselyfalselyfalsely doesn't mean that the complement of his statement would be the truthtruthtruth. If a person is declared falsefalsefalse(i.e not included in the set) after Betty and Jughead pick their set of truth speaking people with non-contradicting statements, the person declared false might not be speaking falselyfalselyfalsely about anyone(except saying he himself is a truetruetrue speaking person which contradicts with the selected statements) but since the selected Set of statements feels him to be a falsefalsefalse speaking person he won't be included in the set. 
But if a person is tagged as truthtruthtruth speaking person then their Statement must be entirely correct and should not contradict with the chosen set of truthtruthtruth speaking people. All truthtruthtruth speaking people mentioned in the selected statements should be part of the set and all the people declared falsefalsefalse in the statements shouldn't be part of the set.
See example for clarity.
Link: https://www.codechef.com/problems/GARGOYLE
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
  int n,m_val,count;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  string str;
  getline(cin,str);
  getline(cin,str);
  map<string,int> m;
  m_val=0;
  for(int i=0;i<n;i++){
    getline(cin,str);
    if(m.find(str)==m.end())
      m[str]=1;
    else
      m[str]++;
    if(i!=n-1)
      getline(cin,str);
  }
  map<string,int>::iterator it=m.begin();
  while(it!=m.end()){
    str=it->first;
    count=it->second;
    int actual=0;
    for(int i=0;i<str.size();i++)
      if(str[i]=='T')
	actual++;
    if(actual==count)
      m_val=max(m_val,actual);
    it++;
  }
  cout<<m_val;
  return 0;
}

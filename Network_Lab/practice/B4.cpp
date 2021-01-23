#include <bit/stdc++.h>
using namespace std;
void display(vector<pair<int,string>> frames){
    for(int i=0;i<frames.size();i++)
      cout<<frames[i].first<<" "<<frames[i].second<<"\n";
}
int main(int argc, char *argv[])
{
  int fsize;
  cout<<"Enter frame size(MTU) for the network: ";
  cin>>fsize;
  cout<<"Enter the message: ";
  string message;
  getline(cin,message);
  getline(cin,message);
  vector<pair<int,string>> frames;
  cout<<"After Fragmentation:-\n";
  int f=1;
  for(int i=0;i<message.size();i+=fsize)
    frames.push_back(make_pair(f++,message.substr(i,fsize)));
  display(frames);
  cout<<"After Shuffling:-\n";
  random_shuffle(frames.begin(),frames.end());
  display(frames);
  cout<<"After Sorting:-\n";
  sort(frames.begin(),frames.end());
  display(frames);
  return 0;
}

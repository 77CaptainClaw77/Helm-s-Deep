#include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<string,pair<string,int>> music;
    while(1){
        char ch;
        cout<<"\n1.Input Song\n2.Search and update\n3.Display\nEnter your choice: ";
        cin>>ch;
        if(ch=='.')break;
        if(ch=='1'){
	  getchar();
	  cout<<"Song Title: ";
	  string song_name;
	  getline(cin,song_name);
	  if(song_name.size()>30){
	    cout<<"30 Characters MAX\nSong Title: ";
	    getline(cin,song_name);
	  }
	  cout<<"Artist Title: ";
	  string artist_name;
	  int rating;
	  getline(cin,artist_name);
	  if(artist_name.size()>30){
	    cout<<"30 Characters MAX\nArtist Title: ";
	    getline(cin,artist_name);
	  }
	  cout<<"Rating: ";
	  cin>>rating;
	  music.insert(make_pair(song_name,make_pair(artist_name,rating)));
        }
        else if(ch=='2'){
	  getchar();
	  cout<<"Enter song title to search for: ";
	  string search_title;
	  getline(cin,search_title);
	  pair<multimap<string,pair<string,int>>::iterator,multimap<string,pair<string,int>>::iterator> res=music.equal_range(search_title);
	  if(res.second==res.first) cout<<"No results!";
	  else{
	    int i=0;
	    multimap<string,pair<string,int>>::iterator st=res.first;
	    while(st!=res.second){
	      cout<<i+1<<". Song Title: "<<st->first;
	      cout<<"\nArtist Name: "<<(st->second).first;
	      cout<<"\nRating: "<<(st->second).second<<"\n\n";
	      st++;
	      i++;
	    }
	    cout<<"Select the song to update: ";
	    int up;
	    while(1){
	      cin>>up;
	      if(up>i || up<0) cout<<"INVALID INDEX\nSelect the song to update: ";
	      else break;
	    }
	    st=res.first;
	    while(up>1){
	      st++; up--;
	    }
	    string new_title=st->first,new_artist=(st->second).first;
	    int new_rating=(st->second).second;
	    music.erase(st);
	    while(1){
	      cout<<"\n1.Update Song title\n2.Update artist \n3.Update song rating\n4.Done\nEnter your choice: ";
	      cin>>up;
	      getchar();
	      if(up==1){cout<<"New Song Title: "; getline(cin,new_title);}
	      else if(up==2){ cout<<"New Artist Name: "; getline(cin,new_artist);}
	      else if(up==3){cout<<"New Rating: "; cin>>new_rating;} 
	      else break;
	    }
	    music.insert(make_pair(new_title,make_pair(new_artist,new_rating)));
	  }
        }
	else{
	  multimap<string,pair<string,int>>::iterator itr=music.begin();
	  while(itr!=music.end()){
	    cout<<"\nSong Title: "<<itr->first;
	    cout<<"\nArtist Name: "<<(itr->second).first;
	    cout<<"\nRating: "<<(itr->second).second<<"\n\n";
	    itr++;
	  }
	}
    }
    return 0;
}

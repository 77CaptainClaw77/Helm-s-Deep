//Another approach for this is to sort the character list and then update occurence count and eliminate unique elements
//This would have a time complexity of around O(nlogn)+O(n)=O(nlogn)
//The other approach is to implement horspool algorithm multiple times which would have a worst case time of O(mn)*occ_count and is
//unstable compared to the search and count method. Also a map is necessary...
//Horspool is unecessary for single character match
//Algorithm to win at a hangman game?
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <SFML/Graphics.hpp>
using namespace std;
//Use vector to store all of user choices made to prevent repitition

void init_charlist(vector<char> &ch_list){  for(int i='a';i<='z';i++) ch_list.push_back(i); }

int main()
{
  sf::RenderWindow window; //main window
  window.create(sf::VideoMode(800,600),"Game Window"); //
  sf::Event ev;//Use to read events
  vector<char> remaining_chars;
  init_charlist(remaining_chars);
  while (window.isOpen())
  {
    while(window.pollEvent(ev))
    {
      switch (ev.type)
      { 
      case sf::Event::Closed:window.close();
      break;
      case sf::Event::KeyPressed:
        { int get_key='a'+ev.KeyPressed;
          if(get_key<'a' || get_key>'z')
          { 
            cout<<"Wrong key";
            break;
          }
          char user_key=(char)get_key;
          //if() Now check is key has already been pressed
        //cout<<(char)get_key;
        break;
        }
      }
    }

  }
  return 0;
}

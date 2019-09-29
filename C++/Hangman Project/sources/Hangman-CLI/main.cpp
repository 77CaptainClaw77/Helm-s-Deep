#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#define WRONG_GUESS 0
#define RIGHT_GUESS 1
#define GAME_OVER_WIN 2
#define GAME_OVER_LOSE 3
#include "../Hangman/fileop.h"
#include "../Hangman/user.h"
using namespace std;
void game_over()
{
    cout<<endl<<"Thank You For Playing"<<endl;
    exit(0);
}
void draw_screen()
{
    for(int i=0;i<40;i++)
        cout<<endl;
}
void draw(string word,string hint,int mistakes)
{
    if(mistakes==0) return;
    cout<<" -------"<<endl;
    cout<<" |    |"<<endl;
    if(mistakes==1) return;
    cout<<" |   ( )"<<endl;
    if(mistakes==2) return;
    cout<<" |    |"<<endl;
    if(mistakes==3) return;
    cout<<" |   /|\\ "<<endl;
    cout<<" |  / | \\"<<endl;
    if(mistakes==4) return;
    cout<<" |    |"<<endl;
    if(mistakes==5) return;
    cout<<" |   / \\"<<endl;
    cout<<" |  /   \\"<<endl;
    if(mistakes==6) return;
    cout<<" |"<<endl;
    cout<<" |"<<endl;
    cout<<" |________________"<<endl;
    cout<<"You Lost"<<endl;
}
int eval_game(string& word,char guess,int& mistakes,string& disp_word)
{
    cout<<word<<"\t"<<guess<<"\t"<<word.length();
    if(word.find(guess)==string::npos)
    {
        cout<<"Wrong Guess";
        mistakes++;
        return WRONG_GUESS;
    }
    while(1)
    {
        if(word.find(guess)!=string::npos)
        {
            disp_word[word.find(guess)]=guess;
            word.erase(std::remove(word.begin(), word.end(), guess), word.end());
            if(isspace(word[0]))
            {
                cout<<"Congragulations!! You guessed the right word!";
                return GAME_OVER_WIN;
            }
        }
        else
        {
            return RIGHT_GUESS;
        }
    }
}
user login()
{
    user usr;
    string u,p;
    while(1)
    {
        cout<<"Enter your username: ";
        cin>>u;
        cout<<"Enter your password: ";
        cin>>p;
        file_operations fop;
        pair<string,string> user_data=fop.get_user(u);
        if(user_data.second!="!")
        {
            if(user_data.second==usr.b64encrypt(p) && user_data.first==u)
                {
                    cout<<endl<<"Login Successful"<<endl;
                    break;
                }
        }
    }
    usr=user(u,p);
    return usr;
}
user signup()
{
    user usr;
    string u,p,rp;
    while(1)
    {
        cout<<endl;
        cout<<"Enter your username: ";
        cin>>u;
        cout<<"Enter your password: ";
        cin>>p;
        cout<<"Re-enter your password: ";
        cin>>rp;
        if(p==rp && usr.password_is_valid(p))
        {
            usr=user(u,p);
            break;
        }
    }
    file_operations fo;
    fo.add_user(u,usr.b64encrypt(p));
    return usr;
}
int main()
{
    user current_user;
    int ch;
    file_operations fop;
    while(1)
    {
        cout<<"1.Login\n2.Signup\n3.Exit";
        cin>>ch;
        if(ch==1)
         {
            current_user=login();
              break;
         }
        else if(ch==2)
         {
            current_user=signup();
            cout<<"Here";
             break;
         }
        else if(ch==3)
            return 0;
        else
            cout<<"Wrong Input. Try Again!"<<endl;
    }
    int win_streak_count=0;
    while(1)
    {
        int stat;
        pair<string,string>word_data=fop.read_word_from_file();
        string word=word_data.first;
        string word_def=word_data.second;
        string word_guessed="";
        int mistakes=0;
        for(char ch:word) word_guessed+="_";
        while(1)
        {
            //cout<<word;
            draw_screen();
            cout<<endl<<"Clue: "<<word_def<<endl;
            cout<<"Mistake Count: "<<mistakes<<endl;
            draw(word,word_def,mistakes);
            if(mistakes>=7)
            {
                stat=GAME_OVER_LOSE;
                break;
            }
            cout<<endl<<"Enter your guess: ";
            fflush(stdin);
            char guess=' ';
            while(isspace(guess))
                guess=getchar();
            stat=eval_game(word,guess,mistakes,word_guessed);
            if(stat==GAME_OVER_WIN)
            {
                break;
            }
        }
        if(stat==GAME_OVER_WIN)
            win_streak_count++;
        else
        {
            win_streak_count=0;
            fop.add_to_scores(current_user.get_uname(),win_streak_count);
            fop.retrieve_high_scores();
            cout<<endl<<"Continue ? Press \'y\' for yes anything else for no: ";
            char cont=getchar();
            if(cont!='y')
            {
                cout<<"Thank you for playing!";
                exit(0);
            }
        }
    }
    return 0;
}

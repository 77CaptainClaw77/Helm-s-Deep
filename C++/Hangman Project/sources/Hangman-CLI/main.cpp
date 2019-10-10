#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <curses.h>
#include <unistd.h>
#define WRONG_GUESS 0
#define RIGHT_GUESS 1
#define GAME_OVER_WIN 2
#define GAME_OVER_LOSE 3
#define RST  "\x1B[0m"
#define KBOLD "\x1B[1m"
#define KUNDL "\x1B[4m"
#define KBLCK "\x1B[30m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST
#include "../Hangman/fileop.h"
#include "../Hangman/user.h"
using namespace std;
void welcome()
{
  	cout<<KRED<<"\t\tH     H   AAAAA   N     N  GGGGGGGG  M     M   AAAAA   N     N"<<endl;
	cout<<KMAG<<"\t\tH     H  A     A  NN    N  G         MM   MM  A     A  NN    N"<<endl;
	cout<<KMAG<<"\t\tH     H  A     A  N N   N  G         M M M M  A     A  N N   N"<<endl;
	cout<<KCYN<<"\t\tHHHHHHH  AAAAAAA  N  N  N  G   GGGG  M  M  M  AAAAAAA  N  N  N"<<endl;
	cout<<KCYN<<"\t\tH     H  A     A  N   N N  G      G  M     M  A     A  N   N N"<<endl;
	cout<<KWHT<<"\t\tH     H  A     A  N    NN  G      G  M     M  A     A  N    NN"<<endl;
	cout<<KWHT<<"\t\tH     H  A     A  N     N  GGGGGGGG  M     M  A     A  N     N"<<RST<<endl<<endl<<endl;
}
void game_over()
{
    cout<<endl<<"Thank You For Playing"<<endl;
    exit(0);
}
void draw_screen()
{
    for(int i=0;i<52;i++)
        cout<<endl;
    for(int i=0;i<33;i++)    
        cout<<"\x1b[A";
}
void draw(string word,string hint,int mistakes)
{
    if(mistakes==0) return;
    cout<<"\t\t\t -------"<<endl;
    cout<<"\t\t\t |    |"<<endl;
    if(mistakes==1) return;
    cout<<"\t\t\t |   ( )"<<endl;
    if(mistakes==2) return;
    cout<<"\t\t\t |    |"<<endl;
    if(mistakes==3) return;
    cout<<"\t\t\t |   /|\\ "<<endl;
    cout<<"\t\t\t |  / | \\"<<endl;
    if(mistakes==4) return;
    cout<<"\t\t\t |    |"<<endl;
    if(mistakes==5) return;
    cout<<"\t\t\t |   / \\"<<endl;
    cout<<"\t\t\t |  /   \\"<<endl;
    if(mistakes==6) return;
    cout<<"\t\t\t |"<<endl;
    cout<<"\t\t\t |"<<endl;
    cout<<"\t\t\t |________________"<<endl;
    cout<<KRED<<"\n\n\n\t\tYou Lost"<<RST<<endl;
}
int eval_game(string orig_word,string& word,char guess,int& mistakes,string& disp_word)
{
    if(word.find(guess)==string::npos)
    {
        cout<<KRED<<endl<<"\t\tWrong Guess!"<<RST<<endl;
        mistakes++;
        return WRONG_GUESS;
    }
    else
    {
        cout<<endl<<"\t\tCorrect Guess!"<<endl;
    }
    
    while(1)
    {
        if(word.find(guess)!=string::npos)
        {
            for(int i=0;i<orig_word.length();i++)
            {
                if(orig_word[i]==guess)
                    disp_word[i]=guess;
            }
            word.erase(std::remove(word.begin(), word.end(), guess), word.end());
            if(isspace(word[0]))
            {
                cout<<"\t\t\n\nCongragulations!! You guessed the right word!";
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
        cout<<endl<<endl;
        cout<<"\t\tEnter your username: ";
        cin>>u;
        cout<<"\t\tEnter your password: ";
        cout<<KBLCK;
        cin>>p;
        cout<<RST;
        file_operations fop;
        pair<string,string> user_data=fop.get_user(u,usr.b64encrypt(p));
        if(user_data.second!="!")
        {
            if(user_data.second==usr.b64encrypt(p) && user_data.first==u)
                {
                    cout<<endl<<KGRN<<"\t\tLogin Successful"<<RST<<endl;
                    break;
                }
        }
        cout<<KRED<<"\t\tUsername or Password is incorrect!"<<RST<<endl;
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
        cout<<"\t\tEnter your username: ";
        cin>>u;
        cout<<"\t\tEnter your password: ";
        cout<<KBLCK;
        cin>>p;
        cout<<RST<<endl;
        cout<<"\t\tRe-enter your password: ";
        cout<<KBLCK;
        cin>>rp;
        cout<<RST<<endl;
        if(p==rp && usr.password_is_valid(p))
        {
            usr=user(u,p);
            break;
        }
        if(p!=rp)
            cout<<KRED<<"\t\tPasswords don\'t match!"<<RST<<endl;
        else
            cout<<KRED<<"\t\tInvalid Password Entered!!"<<RST;
    }
    cout<<KGRN<<"\t\tAccount successfully created!!"<<RST<<endl;
    file_operations fo;
    fo.add_user(u,usr.b64encrypt(p));
    return usr;
}
int main()
{
    welcome();
    cout<<endl<<endl<<"\t\tSelect your desired choice\n\n";
    user current_user;
    int ch;
    file_operations fop;
    while(1)
    {
        cout<<"\t\t1.Login\n\t\t2.Signup\n\t\t3.Exit\n\t\tYour Choice: ";
        cin>>ch;
        if(ch==1)
         {
            current_user=login();
              break;
         }
        else if(ch==2)
         {
            current_user=signup();
            break;
         }
        else if(ch==3)
            return 0;
        else
            cout<<"\t\tWrong Input. Try Again!"<<endl;
    }
    int win_streak_count=0;
    while(1)
    {
        int stat;
        pair<string,string>word_data=fop.read_word_from_file();
        string word=word_data.first;
        string word_def=word_data.second;
        string word_guessed="";
        string orig_word=word;
        int mistakes=0;
        for(int m=0;m<word.length()-1;m++) word_guessed+="_";
        while(1)
        {
            //cout<<word;
            draw_screen();
            cout<<endl<<"\t\tCurrent Status: "<<word_guessed;
            cout<<endl<<"\t\tClue: "<<KYEL<<word_def<<RST<<endl;
            cout<<"\t\tMistake Count: "<<KRED<<mistakes<<RST<<endl;
            cout<<"\t\tStreak: "<<KMAG<<win_streak_count<<RST<<endl<<endl;
            draw(word,word_def,mistakes);
            if(mistakes>=7)
            {
                stat=GAME_OVER_LOSE;
                break;
            }
            cout<<endl<<"\t\tEnter your guess: ";
            fflush(stdin);
            char guess=' ';
            while(isspace(guess))
                guess=getchar();
            stat=eval_game(orig_word,word,guess,mistakes,word_guessed);
            if(stat==GAME_OVER_WIN)
            {
                break;
            }
        }
        if(stat==GAME_OVER_WIN)
            win_streak_count++;
        else
        {
            cout<<endl<<"\t\tThe word was "<<KYEL<<orig_word<<endl<<endl<<RST;
            fop.add_to_scores(current_user.get_uname(),win_streak_count);
            cout<<KWHT;           
            fop.retrieve_high_scores();
            cout<<RST;
            win_streak_count=0;
            cout<<endl<<"\t\tContinue ? Press \'y\' for yes anything else for no: ";
            fflush(stdin);
            char cont=getchar();
            cont=getchar();
            if(cont!='y')
            {
                cout<<"\t\tThank you for playing!";
                exit(0);
            }
        }
    }
    return 0;
}

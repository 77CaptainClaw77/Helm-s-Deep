#ifndef FILEOP_H_INCLUDED
#define FILEOP_H_INCLUDED
// Program to handle all file operations
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../Hangman-CLI/score_sorter.h"
#define WORDFILE "WordList.txt"
using namespace std;
class file_operations
{
    string word;
public: vector<string> read_data(char* filename)
    {
      vector<string> data;
      fstream f_r;
      f_r.open(filename,ios::in);
      while(!f_r.eof())
	{
	  string temp;
	  getline(f_r,temp);
	  data.push_back(temp);
	}
	f_r.close();
      for(string d:data)
	cout<<d<<endl;
      return data;
    }
    void write_data(vector<string> data,char* filename,char sep)
    {
        fstream f_w;
        f_w.open(filename,ios::out|ios::app);
        for(string line:data)
            f_w<<line<<endl;
        f_w.close();
    }
    pair<string,string> read_word_from_file()
    {
        pair<string,string> word;
        int line_count=0;
        fstream f_r;
        f_r.open(WORDFILE,ios::in);
        while(!f_r.eof())
        {
            string temp;
            getline(f_r,temp);
            line_count++;
        }
        srand(time(NULL));
        int rand_word=rand()%line_count;
        line_count=0;
        f_r.clear();
        f_r.seekg(0);
        while(!f_r.eof())
        {
            string temp;
            getline(f_r,temp);
            line_count++;
            if(line_count==rand_word)
            {
                word.first=temp.substr(0,temp.find(':'));
                word.second=temp.substr(temp.find(':')+1,temp.length());
                break;
            }
        }
        f_r.close();
        return word;
    }
    void add_to_scores(string username,int score)
    {
        fstream f_w;
        f_w.open("Scores.txt",ios::out|ios::app);
        f_w<<username<<" "<<score<<endl;
        f_w.close();
    }
    void retrieve_high_scores() // sorting algorithm here
    {
        fstream f_r;
        int score;
        string u_name;
        vector<pair<string,int>> h_scores;
        f_r.open("Scores.txt",ios::in);
        while(!f_r.eof())
        {
            f_r>>u_name;
            f_r>>score;
            h_scores.push_back(pair<string,int>(u_name,score));
        }
        score_sorter so;
        so.quick_sort(h_scores,0,h_scores.size()-1);
        for(size_t i=0;i<h_scores.size();i++)
        {
            if(i==5)
                break;
            cout<<endl<<"High Scores";
            cout<<endl<<h_scores[i].first<<"\t"<<h_scores[i].second<<endl;
        }
        f_r.close();
    }
    pair<string,string> get_user(string username)
    {
        string u,p;
        fstream f_r;
        f_r.open("Users.txt",ios::in);
        while(!f_r.eof())
        {
        getline(f_r,u);
        if(username==u) break;
        getline(f_r,p);
        }
        if(f_r.eof())
            return pair<string,string>("","!");
        getline(f_r,p);
            return pair<string,string>(u,p);
    }
    void add_user(string username,string password) //Create new user use encryption here
    {
        fstream f_w;
        f_w.open("Users.txt",ios::out|ios::app);
        f_w<<endl<<username<<endl<<password;
        f_w.close();
    }
};
#endif // FILEOP_H_INCLUDED

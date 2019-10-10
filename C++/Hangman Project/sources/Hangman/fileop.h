#ifndef FILEOP_H_INCLUDED
#define FILEOP_H_INCLUDED
// Program to handle all file operations
#include <string>
#include <utility>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
using namespace std::chrono; 
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
        auto start=high_resolution_clock::now();
        score_sorter so;
        so.quick_sort(h_scores,0,h_scores.size()-1);
        auto end=high_resolution_clock::now();      
        cout<<endl<<"\t\t\tHigh Scores\n";
        cout<<endl<<"\t\tUsername\tScore"<<endl;
        for(size_t i=0;i<h_scores.size();i++)
        {
            if(i==5)
                break;
            cout<<endl<<"\t\t"<<setw(10)<<left<<h_scores[i].first<<"\t"<<h_scores[i].second<<endl;
        }
        auto duration = duration_cast<microseconds>(end - start); 
        cout<<endl<<"\t\tOperation Performed: Sorting";
        cout<<endl<<"\t\tAlgorithm Used : Quick Sort";
        cout<<endl<<"\t\tNo. of objects sorted: "<<h_scores.size();
        cout<<endl<<"\t\tTime Taken For Sort: "<<duration.count()<<" microseconds";
        start=high_resolution_clock::now();
        //score_sorter so;
        reverse(h_scores.begin(), h_scores.end());
        so.quick_sort(h_scores,0,h_scores.size()-1);
        end=high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        cout<<endl<<"\t\tTime Taken in the Worst Case: "<<duration.count()<<" microseconds";
        f_r.close();
    }
    pair<string,string> get_user(string username,string e_pass)
    {
        string u,p;
        fstream f_r;
        f_r.open("Users.txt",ios::in);
        getline(f_r,u);
        while(1)
        {
            while(!f_r.eof())
            {
            getline(f_r,u);
            if(username==u) break;
            getline(f_r,u);
            }
            getline(f_r,p);
            if(e_pass==p)
                    return pair<string,string>(u,p);
            if(f_r.eof())
                break;
        }
        return pair<string,string>("","!");
        //getline(f_r,p);
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

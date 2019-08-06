//Program To Accept Time From User and Count Upto that Time
#include <iostream>
#include <ctime>//for time functions
using namespace std;
void count_for_duration();
void count_upto_time(long duration);
int main(){
    time_t cur_time;//Current date and time variable
    cur_time=time(NULL);//Get cuurent system time
    cout<<"Current Date Time: "<<ctime(&cur_time);//Printing current time
    count_for_duration();
    return 0;
}
void count_for_duration(){
    long t_lim;  //The amount of time in seconds that is to be counted.
    int h, m, s; //Hours minutes and seconds input from user
    cout << "\nEnter the time to be counted in hh mm ss";
    cin >> h >> m >> s;
    t_lim = h * 3600 + m * 60 + s;
    cout<<"\nCounting by time objects";
    count_upto_time(t_lim);
    cout<<"\nNow counting by clock";
    clock_t start_time = clock(),end_time;
    do
    {
        end_time=clock();
    } while (((long)end_time/CLOCKS_PER_SEC) - ((long)start_time / CLOCKS_PER_SEC) <= t_lim);
}
void count_upto_time(long duration){
    time_t now=time(0);
    time_t later=time(0)+duration;
    while(difftime(now,later)!=0){//Difference between the times
        now=time(0);
    }
}

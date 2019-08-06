#include <iostream>
using namespace std;
class TIME{
    int days,hours,minutes,seconds;

public:TIME(){
        days=0;
        hours=0;
        minutes=0;
        seconds=0;
    }
        friend TIME calctime(TIME[],int);
        void fixtime(){
            if(seconds>=60)
            {
                minutes+=seconds/60;
                seconds=seconds%60;
            }
            if(minutes>=60)
            {
                hours+=minutes/60;
                minutes=minutes%60;
            }
            if(hours>=24)
            {
                days+=hours/24;
                hours=hours%24;
            }
        }
        void make_time(){
            days=0;
            cout<<"\nEnter the number of hours, minutes and seconds in the following format\n\t hh mm ss";
            cin>>hours>>minutes>>seconds;
            validate_time();
        }
        void validate_time(){
            if(hours>=24 || minutes>=60 || seconds>=60){
                cout<<"\nThe time you entered is invalid please enter a valid time";
                make_time();
            }

        }
        void display(){
            cout<<"\n";
            if(days>0){
                cout<<"\n "<<days<<" days";
            }
            cout<<"\n "<<hours<<" hours";
            cout<<"\n "<<minutes<<" minutes";
            cout<<"\n "<<seconds<<" seconds";
        }
};
TIME calctime(TIME tarr[],int n){
    TIME tfin;
    for(int i=0;i<n;i++)
    {
        tfin.seconds+=tarr[i].seconds;
        tfin.minutes+=tarr[i].minutes;
        tfin.hours+=tarr[i].hours;
        tfin.days+=tarr[i].days;
    }
    tfin.fixtime();
    return  tfin;
}
int main(){
    int n;
    cout<<"Enter the number of time objects you want to create";
    cin>>n;
    TIME t[n];
    for(int i=0;i<n;i++){
        TIME ttemp;
        ttemp.make_time();
        t[i]=ttemp;
    }
    for(int j=0;j<n;j++)
        t[j].display();
    TIME result=calctime(t,n);
    cout<<"\nThe result is ";
    result.display();
    return 0;
}

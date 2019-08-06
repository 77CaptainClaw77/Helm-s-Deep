#include <iostream>
#include <string.h>
#include <iomanip>
class batsman{
private:int code;
        char name[20];
        int innings;
        int notout;
        float calcavg();
        int runs;
        float average;
public:void read(float&,char*);
       void display();

};
void batsman::read(float& maxav,char* bestbat){
    std::cout<<"Enter the name";
    std::cin>>name;
    std::cout<<"Enter the id";
    std::cin>>code;
    std::cout<<"Enter the innings";
    std::cin>>innings;
    std::cout<<"Enter the notouts";
    std::cin>>notout;
    std::cout<<"Enter the number of runs";
    std::cin>>runs;
    average=calcavg();
    maxav=maxav>average?maxav:average;
    //char* bestbat=new char[20];
    if(maxav==average)
        strcpy(bestbat,name);
}
float batsman::calcavg(){
    return ((runs+0.0)/(innings-notout));
}
void batsman::display(){

       std::cout<<"\n"<<std::left<<std::setw(5)<<name<<"\t"<<std::setw(3)<<code<<"\t"<<std::setw(4)<<runs<<"\t"<<std::setw(3)<<innings<<"\t"<<std::setw(3)<<notout<<"\t"<<std::setw(4)<<std::setprecision(4)<<average;

}
int main(){
    char* b_bat=new char[20];
    std::cout<<"Enter the number of players";
    int n;
    std::cin>>n;
    batsman bat[n];
    float maxav=0.0;
    for(int i=0;i<n;i++)
    {
        bat[i].read(maxav,b_bat);
    }
    std::cout<<"Name\tID\tRuns\tInnings\tNotouts\tAverage\n";
    for(int i=0;i<n;i++)
        bat[i].display();
    std::cout<<"\n\tThe best batsman is "<<b_bat;
    return 0;
}

#include <iostream>
#include <cstring>
#include <exception>
using namespace std;
class Location{
public:Location(string loc){
        location_name=loc;
        north=NULL;
        west=NULL;
        east=NULL;
        south=NULL;
    };
    Location(){}
    Location* move_north(){
        if(north==NULL)
            throw "\nInvalid Direction\n";
        else
            return north;
    }
    Location* move_south(){
        if(south==NULL)
            throw "\nInvalid Direction\n";
        else
            return south;
    }
    Location* move_east(){
        if(east==NULL)
            throw "\nInvalid Direction\n";
        else
            return east;
    }
    Location* move_west(){
        if(west==NULL)
            throw "\nInvalid Direction\n";
        else
            return west;
    }
    void display()
    {
        cout<<"\nYou are at "<<location_name;
    }
    void set_north(Location* l){
        north=l;
    }
    void set_south(Location* l){
        south=l;
    }
    void set_west(Location* l){
        west=l;
    }
    void set_east(Location* l){
        east=l;
    }
    private:string location_name;
    Location *north,*west,*east,*south;
};
int main(){
    Location* Home=new Location;
    *Home=Location("HOME");
    Location* Forest=new Location;
    Location* Destination=new Location;
    *Forest=Location("FOREST");
    Home->set_north(Forest);
    Destination=Home;
    Destination->display();
    Destination=Destination->move_north();
    Destination->display();
    return 0;
}

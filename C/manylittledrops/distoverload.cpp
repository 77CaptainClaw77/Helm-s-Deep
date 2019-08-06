#include <stdio.h>
#include <math.h>
using namespace std;
class _2DPOINT{
    float x,y;
public:
    _2DPOINT(float x1,float y1){
        x=x1;
        y=y1;
    }
};
class _3DPOINT{
    float x,y,z;
    public:
    _3DPOINT(float x1,float y1,float z1){
        x=x1;
        y=y1;
        z=z1;
    }
};
float distance_calc(_2DPOINT p1,_2DPOINT p2){
    return sqrt(pow(p1.x-p2.x,2.0)+pow(p1.y-p2.y,2.0));
}
float distance_calc(_3DPOINT p1,_3DPOINT p2){
    return sqrt(pow(p1.x-p2.x,2.0)+pow(p1.y-p2.y,2.0)+pow(,p1.z-p2.z,2.0));
}
int main(){
    cout<<"Select the desired option:-\n";
    int ch;
    cin>>ch;
    int x1,x2,x3;
    cout<<"\n1.Distance between 3D points\n2.Distance between 2D points\n3.Exit";
    switch(ch){
        case 1:cout<<"\nEnter the X,Y and Z cordinates of first point"
                cin>>x1>>x2>>x3;
                _3DPOINT p1(x1,x2,x3);
                cout<<"\nEnter the X,Y and Z cordinates of the second point"
                cin>>x1>>x2>>x3;
                _3DPOINT p2(x1,x2,x3);
                float dist=distance_calc(p1,p2);
                cout<<"The distance between the two points is "<<dist;
                break;
        case 2:cout<<"\nEnter the X and Y cordinates of first point"
                cin>>x1>>x2;
                _2DPOINT p1(x1,x2);
                cout<<"\nEnter the X and Y cordinates of the second point"
                cin>>x1>>x2;
                _2DPOINT p2(x1,x2);
                float dist=distance_calc(p1,p2);
                cout<<"The distance between the two points is "<<dist;
                break;
        case 3:exit(0);
                break;
        default:cout<<"Invalid choice";
    }
    return 0;
}

#include <iostream>
#include <cmath>
#define PI atan(1)*4;
using namespace std;
class volume {
private:float r,h;//For Cone and Cylinder
        int a,b,c;//For Cube and Cuboid
        static int count;
public:
  volume (int x):a(x){count++;}
  volume (int x,int y,int z):a(x),b(y),c(z){count++;}
  volume(float x):r(x){count++;}
  volume(float x,float y):r(x),h(y){count++;}
  friend float compute(volume,int);
  ~volume ();
};
int volume::count=0;
enum Shape_set{CUBE=1,CUBOID,CONE,SPHERE};
volume::~volume(){
  cout<<"\nNumber of objects before destructor call:"<<volume::count;
  count--;
  cout<<"\nNumber of objects after destructor call:"<<volume::count;
}
volume init_shape(int ch){
  int  x,y,z;
  float a,b;
  if(ch==1)
  {
    cout<<"\nEnter the edge of the cube";
    cin>>x;
    return volume(x);
  }
  else if(ch==2)
  {
    cout<<"\nEnter the edges of the cuboid";
    cin>>x>>y>>z;
    return volume(x,y,z);
  }
  else if(ch==3)
  {
    cout<<"\nEnter the radius and height of the cone";
    cin>>a>>b;
    return volume(a,b);
  }
  else{
    cout << "\nEnter the radius of the sphere";
    cin >> x;
    return volume(a);
  }
}
float compute(volume v, int ch) {
  volume::count++;
  cout<<"\nInside Compute Function";
  switch(ch){
    case CUBE:return v.a*v.a*v.a;
    case CUBOID:return v.a*v.b*v.c;
    case SPHERE:return v.r*v.r*v.r*(4.0/3.0)*PI;
    case CONE:return v.r*v.r*v.h*(1.0/3.0)*PI;
  }
}
int main()
{
  cout<<"Select the desired option:-";
  int ch;
  while(1){
    /* code */
    cout<<"\n1.Cube\n2.Cuboid\n3.Cone\n4.Sphere\n5.Exit";
    cin>>ch;
    float vol;
    switch (ch)
    {
      case CUBE:
      case CUBOID:
      case CONE:
      case SPHERE:cout<<"\nIn main function";
          {volume v=init_shape(ch);
                  vol=compute(v,ch);
      }
        break;  
      case  5:return 0;
      default:cout<<"\nInvalid Choice";
        break;
    }
    if(ch<5 && ch>0)
      cout<<"\nThe volume is "<<vol;
  }
  return 0;
}

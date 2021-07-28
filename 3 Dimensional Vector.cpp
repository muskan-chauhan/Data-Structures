//Two-object orientd implementation
//given: 
//1)initial position and velocity of a solid body as a 3-D vector
//2)acceleration of a body as a 3-D vector (doesn't change with time)
//3)Granularity of simulation time
//4)Total elapsed time

#include<iostream.h>
#include<conio.h>
#include<cmath.h>

struct v3
{
  double x, y, z;
  double length()
    {x*x+y*y+z*z;}
  v3 sum(v3 const &b)
  {
    v3 v;
    v.x=x+b.x;
    v.y=y+b.y;
    v.z=z+b.z;
    return v;
  }
  v3 scale(double const factor)
  {
    v3 v;
    v.x=x*factor;
    v.y=y*factor;
    v.z=z*factor;
  }
  void print()
  {
    cout<<"x:"<<x<<"y:"<<y<<"z:"<<z<<endl;
  }
};

int main()
{
  v3 vel, acc, pos;               //initial velocity, accelration and initial position
  v3 currDispl, currPos;          //current displacement and position
  double t=0.0, deltaT, totalT;   //t:time elapsed so far

  cout<<"Give x, y and z components of initial velocity: ";
  cin>>vel.x>>vel.y>>vel.z;
  cout<<"Give x, y and z components of accelerations: ";
  cin>>acc.x>>acc.y>>acc.z;
  cout<<"Give x, y and z components of initial position: ";
  cin>>pos.x>>pos.y>>pos.z;
  cout<<"Give total simulation time: ";
  cin>>totalT;
  cout<<"Give simulation time granularity: ";
  cin>>deltaT;
  
  if((totalT<0)||(deltaT<=0))
  {
    cout<<"Invalid input!"<<endl;
    return -1;
  }
  
  while(t<=totalT)
  {                            //calculate current displacement using vel*t+(0.5)*acc*t^2    
    currDispl=(vel.scale(t).sum(acc.scale(0.5*t*t));                                                  
    currPos=currDispl.sum(pos);
    cout<<"Time"<<t<<" ";
    currPos.print();
    t=t+deltaT;
  }
  return 0;
}
   
    
 
    

#include<iostream.h>
#include<conio.h>

struct v3
{
  double x, y, z;
  double length()
  {
    x*x+y*y+z*z;
  }
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
    return v;
  }
  void print()
  {
    cout<<"x:"<<x<<"y:"<<y<<"z:"<<z<<endl;
  }
};

struct MotionSimulator{
  v3 initPos, initVel, acc;
  v3 currPos, currVel;
  double deltaT;
  void initializeSimulator()
  {
    currPos=initPos;
    currVel=initVel;
    return;
  }
  void simulateAStep()
  {
    currPos=currPos.sum(currVel.scale(deltaT));
    currVel=currVel.sum(acc.scale(deltaT));
    return;
  }
  void printPosition()
  {
    currPos.print();
    return;
  }
};

int main()
{
  MotionSimulator mSim;
  double t=0.0, deltaT, totalT;
  cout<<"Give x, y and z components of initial velocity: ";
  cin>>(mSim.initVel).x>>(mSim.initVel).y>>(mmSim.initVel).z;
  cout<<"Give x, y and z components of acceleration: ";
  cin>>(mSim.acc).x>>(msim.acc).y>>(mSim.acc).z;
  cout<<"Give x, y and z components of initial position: ";
  cin>>(mSim.initPos).x>>(mSim.acc).y>>(mSim.acc).z;
  cout<<"Give total simulation time: ";
  cin>>totalT;
  cout<<"Give simulation time granularity: ";
  cin>>deltaT;
  mSim.deltaT=deltaT;
  
  mSim.initializeSimulator();
  while (t<totalT)
  {
    mSim.simulateAStep();
    cout<<"Time: "<<t<<" ";
    mSim.printPosition();
    t=t+deltaT;
  }
  return 0;
}
    
  
  

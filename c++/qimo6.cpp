#include<iostream>
using namespace std;

class Vehicle{
public:
     Vehicle(){
        cout<<"创建交通工具Vehicle"<<endl;
    }
    ~Vehicle(){
        cout<<"销毁交通工具Vehicle"<<endl;
    }
};

class Boat:virtual public Vehicle{
public:
    Boat(){
        cout<<"创建船Boat"<<endl;
    }
    ~Boat(){
        cout<<"销毁船Boat"<<endl;
    }
};

class Car:virtual public Vehicle{
public:
    Car(){
        cout<<"创建汽车Car"<<endl;
    }
    ~Car(){
        cout<<"销毁汽车Car"<<endl;
    }
};

class AmphibianCar:public Car,public Boat{
public:
    AmphibianCar(){
        cout<<"创建水陆两用汽车AmphibianCar"<<endl;
    }
    ~AmphibianCar(){
        cout<<"销毁水陆两用汽车AmphibianCar"<<endl;
    }
};

int main()
{
   int x;
   cin >> x;
   if (x == 1)
   {
      AmphibianCar a;
      cout << endl;
   }
   else if (x == 2)
   {
      Car a;
      cout << endl;
   }
   else if (x == 3)
   {
      Boat a;
      cout << endl;
   }
   else if (x == 4)
   {
      Vehicle a;
      cout << endl;
   }
   return 0;
}

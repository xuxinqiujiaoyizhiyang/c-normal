#include<iostream>
using namespace std;

class Vehicle{
public:
     Vehicle(){
        cout<<"������ͨ����Vehicle"<<endl;
    }
    ~Vehicle(){
        cout<<"���ٽ�ͨ����Vehicle"<<endl;
    }
};

class Boat:virtual public Vehicle{
public:
    Boat(){
        cout<<"������Boat"<<endl;
    }
    ~Boat(){
        cout<<"���ٴ�Boat"<<endl;
    }
};

class Car:virtual public Vehicle{
public:
    Car(){
        cout<<"��������Car"<<endl;
    }
    ~Car(){
        cout<<"��������Car"<<endl;
    }
};

class AmphibianCar:public Car,public Boat{
public:
    AmphibianCar(){
        cout<<"����ˮ½��������AmphibianCar"<<endl;
    }
    ~AmphibianCar(){
        cout<<"����ˮ½��������AmphibianCar"<<endl;
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

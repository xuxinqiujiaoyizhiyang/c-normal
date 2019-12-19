#include<iostream>
using namespace std;

class Zerg{
protected:
    int Minerals;
public:
    Zerg(int a){
        Minerals=a;
    }
    virtual void feed(int m)
    Minerals+=m;}
};

class Drone:public Zerg{
public:
    Drone(int a):Zerg(a){};
    void feed(int m){
        Minerals+=m;
        cout<<"我好饱好饱啊！"<<endl;
    }
    void Show(){
        cout<<Minerals<<endl;
    }
};

class Hydralisk:public Zerg{
public:
    Hydralisk(int a):Zerg(a){};
    void feed(int m){
        Minerals+=m;
        cout<<"还不错，不饿了！"<<endl;
    }
    void Show(){
        cout<<Minerals<<endl;
    }
};

class Lurker:public Zerg{
public:
    Lurker(int a):Zerg(a){};
    void feed(int m){
        Minerals+=m;
        cout<<"没吃够！还要！"<<endl;
    }
    void Show(){
        cout<<Minerals<<endl;
    }
};

void Lair(Zerg &c){
    c.feed(10);
}

int main()
{
   int init1, init2, init3;
   cin >> init1 >> init2 >> init3;

   Drone a(init1);
   Lair(a);

   Hydralisk b(init2);
   Lair(b);

   Lurker c(init3);
   Lair(c);

   a.Show();
   b.Show();
   c.Show();
   return 0;
}

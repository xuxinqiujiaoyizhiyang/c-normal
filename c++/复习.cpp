#include<iostream>

using namespace std;

class A{
public:
    A(int i=3):a(i){};
    friend ostream& operator<<(ostream &os,const A &c);
    A& operator=(const A& c) {
        a=c.a;
        return *this;
    }
    int a;
};

ostream& operator<<(ostream &os,const A &c){
    return os<<c.a;
}

int main(){
    A b(5);
    A a;
    b=a;
    cout<<b;
}

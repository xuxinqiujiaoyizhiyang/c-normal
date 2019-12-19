#include<iostream>

using namespace std;

class A{
public:
    A(){};
    A(int i){
        a=i;
    }
void output(){
        cout<<a;
    }
    int a;
};

class B:public A{
public:
    B(int i):A(i){};
    void output(){
        A::output();
    }
};

int main(){
    B text(10);
    A text1;
    text1=text;
    text.output();
}

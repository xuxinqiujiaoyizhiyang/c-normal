#include<iostream>
#include <stdlib.h>

using namespace std;

class chang{
public:
    chang(int i):r(i),f(r){}
    void print(){
        cout<<r<<k<<f<<endl;
        }
    const int &f;
    static const int k;
private:
    const int r;
};

const int chang::k=1;

class chang1{

public:
    chang1(int i):A(i){}
    void print(){
   A.print();
}
private :
    chang A;
};

int main(){
    int a=1;
    int *v;
    int d=2;
    int e=3;
    v=new int(10);//堆空间，动态分配内存
    cout<<v<<endl;
    delete []v;
    chang B(10);
    chang1 C(11);
    cout<<"k是："<<B.k<<endl;
    B.print();
    C.print();
    int const* b=&a;
    const int *c=&d;
    const int &f=e;
    cout<<*b<<"\n"<<*c<<"\n"<<f<<endl;
}

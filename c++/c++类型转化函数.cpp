#include<iostream>
#include <stdlib.h>

using namespace std;

class A{
public:
    A(int i,int j){
        a=i;
        b=j;
    }
//类型转换函数
operator double(){
    return double(a)/double(b);
     };
private:
    int a;
    int b;
};

int main(){
    A a(10,11);
    double i=1;
    cout<<i+a;
}

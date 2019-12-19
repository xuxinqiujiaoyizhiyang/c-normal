#include<iostream>
#include <iomanip>
using namespace std;

class A{
public:
    A(int i):a(i){};
    int fun(int b){
        return a*b;
    }
private:
    int a;
};

int main(){
    A c(10);
    int a=12;
   int (A::*pfun) (int);
   pfun=&A::fun;
    cout<<c.**pfun(a)<<endl;
    return 0;
}

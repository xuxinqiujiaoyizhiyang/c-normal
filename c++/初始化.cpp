#include <iostream>
using namespace std;
int main(){
    double a=3.14637463827;
    int c{0};//花括号初始化
    int &d=c;//引用必须初始化
    d++;
    cout<<c<<endl;
    return 0;
}

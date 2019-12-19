#include <iostream>

using namespace std;

//内联函数
inline returna(int a){
    return a;
}

class aitem{
public:
    aitem(int a){
        this->a=a;
    }
    aitem(){
        int c;
        cout<<"please input the value of a:";
        cin>>c;
        this->a=c;
    }
//方法的重载
    void returna(){
        cout<<"the value of class.a:"<<this->a<<endl;
    }
    void returna(int i){
        cout<<"The value of a and i:"<<a<<","<<i<<endl;
    }
     void returnb(){
        cout<<"the value of class.a:"<<this->a<<endl;
    }
//静态成员方法
    static void returna(char f){
        cout<<"The value of f:"<<f<<endl;
    }
public:
    int a;
    static char c;//静态数据成员
};

char aitem::c='c';//注意类内部数据成员的访问权限

int main(){
    int i=20;
    int b=10;

    aitem str2[2];
    aitem (*str1)=str2;
    str1->returna();
    (str1+1)->returna();

    int aitem::*n=&aitem::a;//指向数据成员的指针
    void (aitem::*returnb1)()=aitem::returnb;//指向成员函数的指针

    aitem a1(30);
    aitem a2;
    //对象数组
    aitem str[2]={
        aitem(40),
        aitem()
    };
    a1.returna();
    a1.returna(i);
    a1.*returnb1;
    a2.returna();
    a2.returna(i);
    aitem::returna(aitem::c);//用类来声明静态变量和方法时候用::
    a1.returna(a1.c);//和上面一句对比
    cout<<"The value of b:"<<returna(b)<<endl;
    cout<<"The value of c:\n"<<a1.c;
    cout<<"The value of c:"<<a1.*n;
    return 0;
}

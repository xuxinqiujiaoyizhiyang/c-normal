#include <iostream>

using namespace std;

//��������
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
//����������
    void returna(){
        cout<<"the value of class.a:"<<this->a<<endl;
    }
    void returna(int i){
        cout<<"The value of a and i:"<<a<<","<<i<<endl;
    }
     void returnb(){
        cout<<"the value of class.a:"<<this->a<<endl;
    }
//��̬��Ա����
    static void returna(char f){
        cout<<"The value of f:"<<f<<endl;
    }
public:
    int a;
    static char c;//��̬���ݳ�Ա
};

char aitem::c='c';//ע�����ڲ����ݳ�Ա�ķ���Ȩ��

int main(){
    int i=20;
    int b=10;

    aitem str2[2];
    aitem (*str1)=str2;
    str1->returna();
    (str1+1)->returna();

    int aitem::*n=&aitem::a;//ָ�����ݳ�Ա��ָ��
    void (aitem::*returnb1)()=aitem::returnb;//ָ���Ա������ָ��

    aitem a1(30);
    aitem a2;
    //��������
    aitem str[2]={
        aitem(40),
        aitem()
    };
    a1.returna();
    a1.returna(i);
    a1.*returnb1;
    a2.returna();
    a2.returna(i);
    aitem::returna(aitem::c);//������������̬�����ͷ���ʱ����::
    a1.returna(a1.c);//������һ��Ա�
    cout<<"The value of b:"<<returna(b)<<endl;
    cout<<"The value of c:\n"<<a1.c;
    cout<<"The value of c:"<<a1.*n;
    return 0;
}

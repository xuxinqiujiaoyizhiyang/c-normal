#include <iostream>
using namespace std;
int main(){
    double a=3.14637463827;
    int c{0};//�����ų�ʼ��
    int &d=c;//���ñ����ʼ��
    d++;
    cout<<c<<endl;
    return 0;
}

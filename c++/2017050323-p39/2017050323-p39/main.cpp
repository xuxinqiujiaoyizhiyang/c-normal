#include<iostream>
#include"A.h"
#include<stdlib.h>

using namespace std;
int main() {
	//构造三个类A的对象X,Y,Z(未进行赋值的成员数据取值为默认值)
	A X, Y(5), Z(7, 9, 10);
	//输出对象X的成员数据a,b,c
	cout << "X=" << X.aout() << "," << X.bout() << "," << X.cout() << endl;
	//输出对象Y的成员数据a,b,c
	cout << "Y=" << Y.aout() << "," << Y.bout() << "," << Y.cout() << endl;
	//输出对象Z的成员数据a,b,c
	cout << "Z=" << Z.aout() << "," << Z.bout() << ","<< Z.cout() << endl;
	system("pause");
	return 0;
}
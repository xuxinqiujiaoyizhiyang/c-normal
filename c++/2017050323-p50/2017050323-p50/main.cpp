#include<iostream>
#include "Point.h"
#include<stdlib.h>

using namespace std;

//主函数实现
int main() {
	//声明对象A
	Point A(4, 5);
	//输出对象A的成员数据X,Y
	cout << "Point A:" << A.GetX() << "," << A.GetY()<<"\t";
	//输出静态成员变量Z
	cout << "Object id=" << Point::GetC() << endl;
	//根据对象A来进行对象B的拷贝构造
	Point B(A);
	//输出对象B的成员数据X,Y
	cout << "Point B:" << B.GetX() << "," << B.GetY() << "\t";
	//输出静态成员数据Z
	cout << "Object id=" << B.GetC() << endl;
	system("pause");
}
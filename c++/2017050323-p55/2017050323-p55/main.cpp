#include<iostream>
#include"Point.h"
#include<stdlib.h>

using namespace std;
int main() {
	double d1 = 3, d2 = 4, d3 = 6, d4 = 8;
	//构造两个类Point的对象p1,p2
	Point p1(d1, d2), p2(d3, d4);
	//输出p1的成员数据值
	p1.Print();
	//输出p2的成员数据值
	p2.Print();
	//友元调用，同普通函数（求两对象坐标之间的距离）
	double d = Distance(p1, p2);
	//输出两对象坐标的距离
	cout << "Distance=" << d << endl;
	system("pause");
	return 0;
}
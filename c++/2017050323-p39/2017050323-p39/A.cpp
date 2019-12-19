#include<iostream>
#include"A.h"

//实现类A中的行为方法

//构造函数初始化成员数据
A::A(int i, int j, int k) {
	a = i;
	b = j;
	c = k;
}

//输出成员数据a的值
int A::aout() {
	return a;
}

//输出成员数据b的值
int A::bout() {
	return b;
}

//输出成员数据c的值
int A::cout() {
	return c;
}
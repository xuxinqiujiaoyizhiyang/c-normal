#include<iostream>
#include"A.h"

//ʵ����A�е���Ϊ����

//���캯����ʼ����Ա����
A::A(int i, int j, int k) {
	a = i;
	b = j;
	c = k;
}

//�����Ա����a��ֵ
int A::aout() {
	return a;
}

//�����Ա����b��ֵ
int A::bout() {
	return b;
}

//�����Ա����c��ֵ
int A::cout() {
	return c;
}
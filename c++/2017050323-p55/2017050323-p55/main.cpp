#include<iostream>
#include"Point.h"
#include<stdlib.h>

using namespace std;
int main() {
	double d1 = 3, d2 = 4, d3 = 6, d4 = 8;
	//����������Point�Ķ���p1,p2
	Point p1(d1, d2), p2(d3, d4);
	//���p1�ĳ�Ա����ֵ
	p1.Print();
	//���p2�ĳ�Ա����ֵ
	p2.Print();
	//��Ԫ���ã�ͬ��ͨ������������������֮��ľ��룩
	double d = Distance(p1, p2);
	//�������������ľ���
	cout << "Distance=" << d << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include "Point.h"
#include<stdlib.h>

using namespace std;

//������ʵ��
int main() {
	//��������A
	Point A(4, 5);
	//�������A�ĳ�Ա����X,Y
	cout << "Point A:" << A.GetX() << "," << A.GetY()<<"\t";
	//�����̬��Ա����Z
	cout << "Object id=" << Point::GetC() << endl;
	//���ݶ���A�����ж���B�Ŀ�������
	Point B(A);
	//�������B�ĳ�Ա����X,Y
	cout << "Point B:" << B.GetX() << "," << B.GetY() << "\t";
	//�����̬��Ա����Z
	cout << "Object id=" << B.GetC() << endl;
	system("pause");
}
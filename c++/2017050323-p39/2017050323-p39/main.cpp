#include<iostream>
#include"A.h"
#include<stdlib.h>

using namespace std;
int main() {
	//����������A�Ķ���X,Y,Z(δ���и�ֵ�ĳ�Ա����ȡֵΪĬ��ֵ)
	A X, Y(5), Z(7, 9, 10);
	//�������X�ĳ�Ա����a,b,c
	cout << "X=" << X.aout() << "," << X.bout() << "," << X.cout() << endl;
	//�������Y�ĳ�Ա����a,b,c
	cout << "Y=" << Y.aout() << "," << Y.bout() << "," << Y.cout() << endl;
	//�������Z�ĳ�Ա����a,b,c
	cout << "Z=" << Z.aout() << "," << Z.bout() << ","<< Z.cout() << endl;
	system("pause");
	return 0;
}
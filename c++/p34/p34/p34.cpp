#include<iostream>
#include<stdlib.h>

using namespace std;

class Number {
	//����˽�����ݳ�Աi
	int i;
public:
	//�вι��캯�������ݳ�Ա��ʼ��
	Number(int ii = 0) : i(ii) {}
	//��Ա�������������+
	 Number operator+(const Number& n) const { 
		return Number(i + n.i);
	}
	 //������ݳ�Աi
	void couti() {
		cout << i << endl;
	}
	//��Ԫ(ȫ��)�������������-
	friend  Number operator-(const Number&, const Number&);
};
	//��Ԫ��ȫ�֣��������������-ʵ��
	 Number operator-(const Number& n1, const Number& n2) { 
	return Number(n1.i - n2.i);
	}

int main() {
	//��������Number��Ķ���a,b
	Number a(47), b(11);
	a + b; //��ȷ
	a + 1; // ��int�Ͳ�����ת��ΪNumber
	//1 + a; // ERROR���������������Number����
	a - b; // ��ȷ
	a - 1; //��int�Ͳ�����ת��ΪNumber����
	1 - a; //��int�Ͳ�����ת��ΪNumber����(��Ԫ���غ�������)
	//����������
	 (a + b).couti();
	 (a + 1).couti();
	 (a - b).couti();
	 (a - 1).couti();
	 (1 - a).couti();
	system("pause");
	return 0;
}
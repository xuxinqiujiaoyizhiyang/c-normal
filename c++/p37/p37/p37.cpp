#include <iostream>
#include<stdlib.h>
using namespace std;

class complex {
//��������˽�����ݳ�Ա
private:
	double real, image;
public:
	//�вι��캯��
	complex(double r = 0, double i = 0) {
		real = r; image = i;
	}
	//��Ա�������������+
	const complex operator+(const complex& right)  const {
		return complex(real + right.real, image + right.image);//ʵ�����鲿�ֱ����
	}
	//ȫ�ֺ�������������������
	friend ostream& operator<<(ostream& os, const complex& c);
	friend istream&  operator>>(istream& is, complex& c);
};

//ʵ������������������
ostream& operator<<(ostream& os, const complex& c) {
	//���ʵ���鲿���ݳ�Ա��Ϊ0�����0
	if (c.real == 0 && c.image == 0) { os << "0"; }
	//���ʵ����Ϊ0�����ʵ��
	if (c.real != 0) { os << c.real; }
	//����鲿��Ϊ0
	if (c.image != 0) {
		//���ʵ�����ݳ�Ա����0���鲿���ݳ�Ա����Ϊ0�����+
		if (c.image > 0 && c.real != 0)
			os << "+";
		os << c.image << "i";
	}
	return os; //����ostream���������ʽ���ʽ
}

//ʵ�������������������
istream& operator>>(istream& is, complex& c) {
	cout << "please input a complex:";
	//������ݳ�Աreaal,image
	return is >> c.real >> c.image;
}

int main() {
	complex c1, c2;
	//�����������뺯��
	cin >> c1;
	cin >> c2;
	//���������������
	cout << c1 + c2 << endl; //����ȫ�ֺ���operator<<
	system("pause");
	return 0;
}


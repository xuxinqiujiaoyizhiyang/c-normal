#include<iostream>

using namespace std;

//��X����������ʵ��
class X {
	//������Ԫ��Y
	friend class Y;
public:
	//���캯��
	X(int i) {
		x = i;
	}
	//�����ĳ�Ա����
	void Print() {
		cout << "x=" << x << endl;
	}
	//������Ա����x�Լ���̬��Ա����s
private:
	int x;
	static int s;
};
//��ʼ����̬��Ա����s
int X::s = 5;
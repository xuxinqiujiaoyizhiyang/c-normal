#include<iostream>
using namespace std;

//��Y����������ʵ��
class Y {
public:
	//���캯��
	Y(int i) {
		y = i;
	}
	//�����X�ĳ�Ա����x�Լ���Y�ĳ�Ա����y
	void Print(X &r) {
		cout << "x=" << r.x << "," << "y=" << y << endl;
		//����ʹ����X��˽�г�Ա����
	}
	//����˽�г�Ա����
private:
	int y;
};

#include<iostream>
#include<stdlib.h>

using namespace std;


class Y;//�������
class X {
public:
	// ͨ������ת�������������X��Y��ת��
	//operator Y() const;
};

class Y {
public:
	// ͨ����Y�Ĺ��캯������X��Y��ת��
	Y(X) {} 
};

//��C�е�����ת������ʵ��
/*X::operator Y() const{
	//������Y�Ķ���
	return Y();
}*/

void f(Y) {}

int main() {
	X a;//������X�Ķ���a
	f(a); //��������Y�Ķ�������X�Ķ����Զ�ת������������������������
	system("pause");
	return 0;
}


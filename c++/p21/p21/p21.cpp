#include<iostream>
#include<assert.h>
#include<stdlib.h>

using namespace std;

class Byte {
	//����˽�����ݳ�Ա�ַ�����b
	unsigned char b;
public:
	//�вι��캯�������ݳ�Ա���г�ʼ��
	Byte(unsigned char bb = 0) : b(bb) {}
	//��Ա�������ض�Ԫ�����+
	const Byte operator+(const Byte& right) const { return Byte(b + right.b); }
	//��Ա�������ض�Ԫ�����-
	const Byte operator-(const Byte& right) const { return Byte(b - right.b); }
	//��Ա�������ض�Ԫ�����*
	const Byte operator*(const Byte& right) const { return Byte(b * right.b); }
	//��Ա�������ض�Ԫ�����/
	const Byte operator/(const Byte& right) const {
		assert(right.b != 0);//�жϼ���ĸ�Ƿ�Ϊ0
		return Byte(b / right.b);
	}
	//��Ա��������λ�����%
	const Byte operator%(const Byte& right) const {
		assert(right.b != 0);//�жϼ���ĸ�Ƿ�Ϊ0
		return Byte(b % right.b);
	}
	//��Ա��������λ�����^
	const Byte operator^(const Byte& right) const {
		return Byte(b ^ right.b);
	}
	//��Ա��������λ�����&
	const Byte operator&(const Byte& right) const {
		return Byte(b & right.b);
	}
	//��Ա��������λ�����|
	const Byte operator|(const Byte& right) const {
		return Byte(b | right.b);
	}
	//��Ա��������λ�����<<
	const Byte operator<<(const Byte& right) const {
		return Byte(b << right.b);
	}
	//��Ա��������λ�����>>
	const Byte operator>>(const Byte& right) const {
		return Byte(b >> right.b);
	}
	//��Ա�������ظ�ֵ�����
	Byte& operator=(const Byte& right) { // ֻ���ó�Ա��������
		if (this == &right) return *this; // �Ը�ֵ���
		b = right.b;
		return *this;
	}
	//��Ա�������ظ��ϸ�ֵ�����+=
	Byte& operator+=(const Byte& right) {
		b += right.b;
		return *this;
	}
	//��Ա�������ظ��ϸ�ֵ�����/=
	Byte& operator/=(const Byte& right) {
		assert(right.b != 0);//�жϼ���ĸ�Ƿ�Ϊ0
		b /= right.b;
		return *this;
	}
	//��Ա�������ظ��ϸ�ֵ�����^=
	Byte& operator^=(const Byte& right) {
		b ^= right.b;
		return *this;
	}
	//��Ա�������ع�ϵ�����==
	bool operator==(const Byte& right) const {
		return b == right.b;
	}
	//��Ա�������ع�ϵ�����!=
	bool operator!=(const Byte& right) const {
		return b != right.b;
	}
	//��Ա�������ع�ϵ�����<
	bool operator<(const Byte& right) const {
		return b < right.b;
	}
	//��Ա�������ض�Ԫ�߼������&&
	bool operator&&(const Byte& right) const {
		return b && right.b;
	}
	//��Ա�������ض�Ԫ�߼������||
	bool operator||(const Byte& right) const {
		return b || right.b;
	}
}; 

int main() {
	system("pause");
	return 0;
}
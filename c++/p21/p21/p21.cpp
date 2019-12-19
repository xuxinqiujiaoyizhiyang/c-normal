#include<iostream>
#include<assert.h>
#include<stdlib.h>

using namespace std;

class Byte {
	//声明私有数据成员字符类型b
	unsigned char b;
public:
	//有参构造函数对数据成员进行初始化
	Byte(unsigned char bb = 0) : b(bb) {}
	//成员函数重载二元运算符+
	const Byte operator+(const Byte& right) const { return Byte(b + right.b); }
	//成员函数重载二元运算符-
	const Byte operator-(const Byte& right) const { return Byte(b - right.b); }
	//成员函数重载二元运算符*
	const Byte operator*(const Byte& right) const { return Byte(b * right.b); }
	//成员函数重载二元运算符/
	const Byte operator/(const Byte& right) const {
		assert(right.b != 0);//中断检测分母是否为0
		return Byte(b / right.b);
	}
	//成员函数重载位运算符%
	const Byte operator%(const Byte& right) const {
		assert(right.b != 0);//中断检测分母是否为0
		return Byte(b % right.b);
	}
	//成员函数重载位运算符^
	const Byte operator^(const Byte& right) const {
		return Byte(b ^ right.b);
	}
	//成员函数重载位运算符&
	const Byte operator&(const Byte& right) const {
		return Byte(b & right.b);
	}
	//成员函数重载位运算符|
	const Byte operator|(const Byte& right) const {
		return Byte(b | right.b);
	}
	//成员函数重载位运算符<<
	const Byte operator<<(const Byte& right) const {
		return Byte(b << right.b);
	}
	//成员函数重载位运算符>>
	const Byte operator>>(const Byte& right) const {
		return Byte(b >> right.b);
	}
	//成员函数重载赋值运算符
	Byte& operator=(const Byte& right) { // 只能用成员函数重载
		if (this == &right) return *this; // 自赋值检测
		b = right.b;
		return *this;
	}
	//成员函数重载复合赋值运算符+=
	Byte& operator+=(const Byte& right) {
		b += right.b;
		return *this;
	}
	//成员函数重载复合赋值运算符/=
	Byte& operator/=(const Byte& right) {
		assert(right.b != 0);//中断检测分母是否为0
		b /= right.b;
		return *this;
	}
	//成员函数重载复合赋值运算符^=
	Byte& operator^=(const Byte& right) {
		b ^= right.b;
		return *this;
	}
	//成员函数重载关系运算符==
	bool operator==(const Byte& right) const {
		return b == right.b;
	}
	//成员函数重载关系运算符!=
	bool operator!=(const Byte& right) const {
		return b != right.b;
	}
	//成员函数重载关系运算符<
	bool operator<(const Byte& right) const {
		return b < right.b;
	}
	//成员函数重载二元逻辑运算符&&
	bool operator&&(const Byte& right) const {
		return b && right.b;
	}
	//成员函数重载二元逻辑运算符||
	bool operator||(const Byte& right) const {
		return b || right.b;
	}
}; 

int main() {
	system("pause");
	return 0;
}
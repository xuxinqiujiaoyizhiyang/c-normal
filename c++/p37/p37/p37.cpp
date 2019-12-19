#include <iostream>
#include<stdlib.h>
using namespace std;

class complex {
//声明两个私有数据成员
private:
	double real, image;
public:
	//有参构造函数
	complex(double r = 0, double i = 0) {
		real = r; image = i;
	}
	//成员函数重载运算符+
	const complex operator+(const complex& right)  const {
		return complex(real + right.real, image + right.image);//实部，虚部分别相加
	}
	//全局函数重载输入输出运算符
	friend ostream& operator<<(ostream& os, const complex& c);
	friend istream&  operator>>(istream& is, complex& c);
};

//实现重载输出运算符函数
ostream& operator<<(ostream& os, const complex& c) {
	//如果实部虚部数据成员均为0，输出0
	if (c.real == 0 && c.image == 0) { os << "0"; }
	//如果实部不为0，输出实部
	if (c.real != 0) { os << c.real; }
	//如果虚部不为0
	if (c.image != 0) {
		//如果实部数据成员大于0，虚部数据成员均不为0，输出+
		if (c.image > 0 && c.real != 0)
			os << "+";
		os << c.image << "i";
	}
	return os; //返回ostream对象便于链式表达式
}

//实现重载输入运算符函数
istream& operator>>(istream& is, complex& c) {
	cout << "please input a complex:";
	//输出数据成员reaal,image
	return is >> c.real >> c.image;
}

int main() {
	complex c1, c2;
	//调用重载输入函数
	cin >> c1;
	cin >> c2;
	//调用重载输出函数
	cout << c1 + c2 << endl; //调用全局函数operator<<
	system("pause");
	return 0;
}


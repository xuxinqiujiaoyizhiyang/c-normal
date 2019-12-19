#include<iostream>
#include<stdlib.h>

using namespace std;

class Number {
	//声明私有数据成员i
	int i;
public:
	//有参构造函数给数据成员初始化
	Number(int ii = 0) : i(ii) {}
	//成员函数重载运算符+
	 Number operator+(const Number& n) const { 
		return Number(i + n.i);
	}
	 //输出数据成员i
	void couti() {
		cout << i << endl;
	}
	//友元(全局)函数重载运算符-
	friend  Number operator-(const Number&, const Number&);
};
	//友元（全局）函数重载运算符-实现
	 Number operator-(const Number& n1, const Number& n2) { 
	return Number(n1.i - n2.i);
	}

int main() {
	//创建两个Number类的对象a,b
	Number a(47), b(11);
	a + b; //正确
	a + 1; // 右int型操作数转换为Number
	//1 + a; // ERROR：左操作数必须是Number类型
	a - b; // 正确
	a - 1; //右int型操作数转换为Number类型
	1 - a; //左int型操作数转换为Number类型(友元重载函数调用)
	//输出上述结果
	 (a + b).couti();
	 (a + 1).couti();
	 (a - b).couti();
	 (a - 1).couti();
	 (1 - a).couti();
	system("pause");
	return 0;
}
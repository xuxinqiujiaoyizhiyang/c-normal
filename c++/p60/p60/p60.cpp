#include<iostream>
#include<stdlib.h>

using namespace std;


class Y;//类的声明
class X {
public:
	// 通过类型转换运算符来进行X到Y的转换
	//operator Y() const;
};

class Y {
public:
	// 通过类Y的构造函数进行X到Y的转换
	Y(X) {} 
};

//类C中的类型转换方法实现
/*X::operator Y() const{
	//返回类Y的对象
	return Y();
}*/

void f(Y) {}

int main() {
	X a;//创建类X的对象a
	f(a); //由于由类Y的对象向类X的对象自动转换有两个方法，产生二义性
	system("pause");
	return 0;
}


#include<iostream>

using namespace std;

//类X的声明及其实现
class X {
	//声明友元类Y
	friend class Y;
public:
	//构造函数
	X(int i) {
		x = i;
	}
	//输出类的成员数据
	void Print() {
		cout << "x=" << x << endl;
	}
	//声明成员数据x以及静态成员数据s
private:
	int x;
	static int s;
};
//初始化静态成员数据s
int X::s = 5;
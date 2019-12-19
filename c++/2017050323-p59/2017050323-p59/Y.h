#include<iostream>
using namespace std;

//类Y的声明及其实现
class Y {
public:
	//构造函数
	Y(int i) {
		y = i;
	}
	//输出类X的成员数据x以及类Y的成员数据y
	void Print(X &r) {
		cout << "x=" << r.x << "," << "y=" << y << endl;
		//可以使用类X的私有成员数据
	}
	//声明私有成员变量
private:
	int y;
};

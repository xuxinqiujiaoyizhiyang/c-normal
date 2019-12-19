#include<iostream>
using namespace std;
//类的声明及其实现
class Point {
public:
	//构造函数
	Point(double i, double j)
	{
		x = i;
		y = j;
	}
	//输出类的成员数据x,y（坐标形式输出）
	void Print() {
		cout << '(' << x << ',' << y << ')' << endl;
	}
	//友元函数的声明(求坐标之间的距离)
	friend double Distance(Point a, Point b);
	//声明私有成员变量
private:
	double x, y;
};

//友元函数的实现（可以访问类的私有成员变量）
double Distance(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy * dy);
}
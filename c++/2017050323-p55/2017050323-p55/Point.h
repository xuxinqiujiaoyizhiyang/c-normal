#include<iostream>
using namespace std;
//�����������ʵ��
class Point {
public:
	//���캯��
	Point(double i, double j)
	{
		x = i;
		y = j;
	}
	//�����ĳ�Ա����x,y��������ʽ�����
	void Print() {
		cout << '(' << x << ',' << y << ')' << endl;
	}
	//��Ԫ����������(������֮��ľ���)
	friend double Distance(Point a, Point b);
	//����˽�г�Ա����
private:
	double x, y;
};

//��Ԫ������ʵ�֣����Է������˽�г�Ա������
double Distance(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy * dy);
}
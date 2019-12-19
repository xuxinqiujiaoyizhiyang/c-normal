//类Point的声明及其实现
class Point {
public:
	//构造函数（其中给成员变量进行了默认值赋值）
	Point(int xx = 0, int yy = 0){
		X = xx;
		Y = yy;
		countP++;//进行一次构造则对静态成员变量进行一次自增
	}
	//拷贝构造函数
	Point(Point &p) {
		X = p.X;
		Y = p.Y;
		countP++;//进行一次拷贝构造则对静态成员变量进行一次自增
	}
	//输出成员数据X的值
	int GetX(){
		return X;
	}
	//输出成员数据Y的值
	int GetY() {
		return Y;
	}
	//输出静态成员数据countP的值
	static int GetC() {
		return countP;
	}
	//声明成员数据X,Y，以及静态成员变量countP
private:
	int X, Y;
	static int countP;
};
//对静态成员变量进行初始化
int Point::countP = 0;


//声明类A的数据成员及其行为方法
class A{
public:
	A(int i = 8, int j = 10, int k = 12);//构造函数中进行数据成员初始化（并且为数据成员赋值了默认值）
	int aout();//输出数据成员a的值
	int bout();//输出数据成员b的值
	int cout();//输出数据成员c的值
private:
	int a, b, c;//声明三个数据成员a,b,c
};

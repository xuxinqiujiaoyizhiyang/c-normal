#include<iostream>
#include<string.h>
using namespace std;

class my_string {
	char *str;
	int len;
public:
	//构造函数
	my_string(const char *s = "") {
		len = strlen(s);
		str = new char[len + 1];//动态申请空间
		strcpy(str, s);//数据成员字符串赋值
	}
	//析构函数，释放所有申请空间
	~my_string() { delete[]str; }
	//赋值运算符重载
	my_string& operator=(const my_string& s) {
		if (this == &s) return *this;//检测自赋值，this指针指向本身对象
		delete[]str;//释放数据成员字符串原有空间
		len = strlen(s.str);
		str = new char[len + 1];//动态申请空间
		strcpy(str, s.str);//数据成员字符串赋值
		return *this;
	}
	//输出数据成员字符串
	void coutstr() {
		cout << str << endl;
	}
};

int main() {
	//构造类my_string的两个对象a,b
	my_string a("abcde"), b("hijk");
	//调用类my_string的重载赋值运算符，将b中的数据成员字符串中的值赋给a中的数据成员字符串
	a = b;
	//调用成员函数输出数据成员字符串
	a.coutstr();
	b.coutstr();
	system("pause");
	return 0;
}
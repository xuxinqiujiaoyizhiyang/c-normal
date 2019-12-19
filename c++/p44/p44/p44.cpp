#include<iostream>
#include<string.h>
using namespace std;

class my_string {
	char *str;
	int len;
public:
	//���캯��
	my_string(const char *s = "") {
		len = strlen(s);
		str = new char[len + 1];//��̬����ռ�
		strcpy(str, s);//���ݳ�Ա�ַ�����ֵ
	}
	//�����������ͷ���������ռ�
	~my_string() { delete[]str; }
	//��ֵ���������
	my_string& operator=(const my_string& s) {
		if (this == &s) return *this;//����Ը�ֵ��thisָ��ָ�������
		delete[]str;//�ͷ����ݳ�Ա�ַ���ԭ�пռ�
		len = strlen(s.str);
		str = new char[len + 1];//��̬����ռ�
		strcpy(str, s.str);//���ݳ�Ա�ַ�����ֵ
		return *this;
	}
	//������ݳ�Ա�ַ���
	void coutstr() {
		cout << str << endl;
	}
};

int main() {
	//������my_string����������a,b
	my_string a("abcde"), b("hijk");
	//������my_string�����ظ�ֵ���������b�е����ݳ�Ա�ַ����е�ֵ����a�е����ݳ�Ա�ַ���
	a = b;
	//���ó�Ա����������ݳ�Ա�ַ���
	a.coutstr();
	b.coutstr();
	system("pause");
	return 0;
}
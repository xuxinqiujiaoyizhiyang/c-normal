#include<iostream>
#include<string>
using namespace std;

void Swap(string &x,string &y){
    string z;
    z=x;
    x=y;
    y=z;
}


int main()
{
   string s[] = {"����", "�ŷ�", "����", "�����"};
   int a, b;
   cin >> a >> b;
   Swap(s[a], s[b]); //����ִ����Ϻ�ʵ�ε�ֵ������

   for(int i = 0; i < 4; i++)
      cout << s[i] << " ";
   cout << endl;
   return 0;
}

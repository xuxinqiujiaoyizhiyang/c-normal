#include<iostream>
using namespace std;//��Ҫ��ͷ�ļ��ȣ�����Ϊ�������
class Test//Test��
{
protected:
    int x,y;//���屣����int���͵����ݳ�Աx��y
public:
    Test(int a=0,int b=0):x(a),y(b){}//��������int���Ͳ���a��b���Ҳ���Ĭ��ֵ��Ϊ0�Ĺ��캯�����ڳ�ʼ���б��У����β�a�������ݳ�Աx��b����y
~Test(){
    cout<<x<<" "<<y<<endl;
    }//�����������ں����������x��y��ֵ����Ļ����ռһ�У�����ֵ֮����һ���ո����
};
int main()
{
    Test t1;//����Test����t1
    Test *t2;   //����Testָ��t2
   int a, b;

   for(int i = 0; i < 2; i++)
   {
        cin >> a >> b;
        t2= new  Test(a, b); //����Test�Ѷ��󣬲�����ַ����ָ��t2
        delete t2; //�ͷŶѶ���
   }
   return 0;
}

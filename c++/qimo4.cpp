   #include<iostream>
   #include<iomanip>
   using namespace std; //��Ҫ��ͷ�ļ��ȣ�����Ϊ�������
   class Point   //�������Point
{
  protected:
    int x,y;//���屣�����ݳ�Ա��int���͵�x��y

  public:
    Point(){
        x=0;y=0;
        }//�޲�Ĭ�Ϲ��캯�����ں������г�ʼ�����ݳ�Աx��yΪ0

      Point(int x1,int y1){
        x=x1;y=y1;
      }//����������������û��Ĭ��ֵ���Ĺ��캯�����ں������н��β�x1��y1�ֱ𸳸����ݳ�Աx��y

      void setX(int x1){
            x=x1;
        }//����x����ĺ���setX(int), ���β�x1�������ݳ�Աx

      void setY(int y1){
        y=y1;
      }//����y����ĺ���setY(int), ���β�y1�������ݳ�Աy

      int getX(){
        return x;
      }//����x����ĺ���getX()

      int getY(){
        return y;
      }//����y����ĺ���getY()
};
class Circle
{
  protected:
    Point center;
    int radius;//���屣�����ݳ�Ա��Point���͵�Բ������center��int���͵İ뾶radius
public:
    Circle(int x=0){
        radius=x;
    }//Ĭ�Ϲ��캯�����ڳ�ʼ���б��г�ʼ���Ӷ���center������Բ������Ϊ0��0���ں������У�����radius�뾶Ϊ0

    Circle(int x1,int y1,int z1=1):center(x1,y1){
        radius=z1;
    }//����������x1��y1��r1�Ĺ��캯�����ڳ�ʼ���б��г�ʼ���Ӷ���center������Բ������Ϊx1��y1���ں������У�����radius�뾶Ϊr1

    const double area(){
            return 3.14*radius*radius;
        }//���㲢����Բ�������Ա����area()��piʹ��3.14��

    int getX(){
        return center.getX();
    }//����Բ������center��x����ĳ�Ա����getX()��

    int getY(){
            return center.getY();
        }//����Բ������center��y����ĳ�Ա����getY()
};
int main()
{
   int x1, y1, r1;
   cin >> x1 >> y1 >> r1;
   Circle a(x1, y1, r1), b;
    cout<< "������2��Բ����a��b" << endl;
   cout << "Բa��Բ������" <<  a.getX() << "��" << a.getY()   << endl;
   cout << "Բb��Բ������" <<   b.getX() << "��" <<  b.getY()  << endl;
   cout << "Բa�����Ϊ" <<setiosflags(ios::fixed)<<setprecision(2)<<a. area()<<endl;//ע��������Ҫ��С�������뱣��2λ��Ч���֣��������룩�����㲹��
   cout << "Բb�����Ϊ" <<setiosflags(ios::fixed)<<setprecision(2)<<b. area()<<endl;//ע��������Ҫ��С�������뱣��2λ��Ч���֣��������룩�����㲹��
   return 0;
}

#include<iostream>

using namespace std;
class Rectangle
   {
      private:
         int x1;
         int y1;
         int x2;
         int y2;
      public:
         void Set2Point(int a, int b, int c, int d)
         {
            x1 = a;
            y1 = b;
            x2 = c;
            y2 = d;
         }
         int area()
         {
            return abs(x1 - x2) * abs(y1 - y2);
         }
   };
   int main()
   {
      int a, b, c, d;
      cout << "请输入长方形的左上角的坐标：" << endl;
      cin >> a >> b;
      cout << "请输入长方形的右下角的坐标：" << endl;
      cin >> c >> d;

      Rectangle r1;
      r1.Set2Point(a,b,c,d);

      a = r1.area();
      cout << "长方形的面积为：" << a;
      return 0;
   }

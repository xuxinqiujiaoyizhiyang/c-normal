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
   string s[] = {"关羽", "张飞", "刘备", "诸葛亮"};
   int a, b;
   cin >> a >> b;
   Swap(s[a], s[b]); //函数执行完毕后，实参的值被交换

   for(int i = 0; i < 4; i++)
      cout << s[i] << " ";
   cout << endl;
   return 0;
}

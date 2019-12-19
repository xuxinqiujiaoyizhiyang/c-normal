#include <iostream>

using namespace std;

class point{
public:
    void InitP(float xx=0,float yy=0)
    {
        x=xx;y=yy;
    }
    void Move(float xOff,float yOff)
    {
        x+=xOff;
        y+=yOff;
    }
    float GetX(){return x;}
    float GetY(){return y;}
private:
    float x,y;
};

class Rectangle:public point{
public:
    void InitR(float x,float y,float w,float h){
        InitP(x,y);
        W=w;H=h;
    }
    float GetH(){return H;}
    float GetW(){return W;}
private:
    float W,H;
};

int main(){
    Rectangle x;
    x.InitR(1,2,3,4);
    cout<<x.GetX()<<',' <<x.GetY()<<','
		<<x.GetH()<<','<<x.GetW()<<endl;
		return 0;
}

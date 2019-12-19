#include<iostream>
#include<iostream>

using namespace std;

class Rational{
public:
    Rational(){}
    Rational(int i,int j){
        if(j!=0){
        zi=i,mu=j;}
    }
    Rational operator+(const Rational &c)const {
        return Rational(zi*c.mu+c.zi*mu,mu*c.mu);
    }
    Rational operator-(const Rational &c)const {
        return Rational(zi*c.mu-c.zi*mu,mu*c.mu);
    }
    Rational operator*(const Rational &c)const {
        return Rational(zi*c.zi,mu*c.mu);
    }
    void Show(){
        if(zi<mu){
            for(int j=2;j<=abs(zi);j++){
                    if(zi%j==0&&mu%j==0){
                        zi=zi/j;
                        mu=mu/j;
                    }
                }
                cout<<zi<<"/"<<mu<<endl;
            }
            else {
                for(int j=2;j<=abs(mu);j++){
                    if(zi%j==0&&mu%j==0){
                        zi=zi/j;
                        mu=mu/j;
                    }
                }
                cout<<zi<<"/"<<mu<<endl;
            }
    }
private:
    int zi;
    int mu;
};

int main()
{
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   Rational r1(a, b), r2(c, d), r3;	//创建有理数对象
   cout << "r1 = ";
   r1.Show();
   cout << "r2 = ";
   r2.Show();
   r3 = r1 + r2;
   cout << "r1 + r2 = ";
   r3.Show();

   r3 = r1 - r2;
   cout << "r1 - r2 = ";
   r3.Show();

   r3 = r1 * r2;
   cout << "r1 * r2 = ";
   r3.Show();
   return 0;
}

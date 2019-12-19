#include<iostream>
#include<stdlib.h>

using namespace std;

class Minint{
public:
    Minint(int i){
        b=i;
    }
    Minint operator-(){
        return Minint(-b);
    }
    Minint operator+(const Minint &rv){
        return Minint(b+rv.b);
    }
    Minint operator+=(const Minint &rv){
        b+=rv.b;
        return *this;
    }
    //前缀
    Minint &operator++(){
        b++;
        return *this;
    }
    //后缀
    Minint& operator++(int){
        Minint before(b);
        b++;
        return before;
    }
     //前缀
    Minint& operator--(){
        b--;
        return *this;
    }
    //后缀
    Minint operator--(int){
        Minint before(b);
        b--;
        return before;
    }
    const Minint operator+(){
        return Minint(b);
    }
    const Minint operator~(){
        return Minint(~b);
    }
    const Minint operator!(){
        return Minint(!b);
    }
    Minint* operator&(){
        return this;
    }
    int b;
};

class operate{
public:
    operate(int j):i(j){}
    friend const operate& operator+(const operate &a);
    friend const operate operator-(const operate &a);
    friend const operate operator~(const operate &a);
    friend  operate* operator&( operate &a);
    friend bool operator!(const operate &a);
    friend const operate& operator++(operate &a);//前缀
    friend const operate operator++(operate &a,int);//后缀
    friend const operate operator--(operate &a);//前缀
    friend const operate operator--(operate &a,int);//后缀
private:
    int i;
    operate* This(){
        return this;
    }
};

const operate& operator+(const operate &a){
    return a;
}

const operate operator-(const operate &a){
    return operate(-a.i);
}

const operate operator~(const operate &a){
    return operate(~a.i);
}

 operate* operator&( operate &a){
    return a.This();
}

bool operator!(const operate &a){
    return !a.i;
}

const operate& operator++(operate &a){
    a.i++;
    return a;
}

const operate operator++(operate &a,int){
   operate before(a.i);
    a.i++;
    return before;
}

int main(){
    Minint A(10),B(11),C(12);
    cout<< (A+=-B+C).b;
}

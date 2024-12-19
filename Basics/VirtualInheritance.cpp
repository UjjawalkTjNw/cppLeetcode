#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int a;
};

class B1: virtual public A{
    public:
    int b1;
};

class B2: virtual public A{
    public:
    int b2;
};

class c : public B1, public B2{
    public:
    int c;
};

int main(){
    c obj;
    obj.a =5;
    cout << obj.a << endl;
    return 0;
}
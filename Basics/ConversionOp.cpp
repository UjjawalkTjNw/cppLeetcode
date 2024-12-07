#include<bits/stdc++.h>
using namespace std;

class BaseA{
    public:
    int i;
    BaseA(int ii =0) : i(ii){}
};

class BaseB{
    public:
    int x;
    BaseB(int xx) : x(xx) {}
    operator BaseA{} const{
        return BaseA(x);
    }
};

int main(){
    BaseA a = BaseB(10);
    return 0;
}
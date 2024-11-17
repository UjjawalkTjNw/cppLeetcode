#include <iostream>

using namespace std;

class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i = 0) {real = r;   imag = i;}

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (const Complex& obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An object of Complex is returned
    cout << c3.real << " + i" << c3.imag << endl;  //op = 12 + i9
}
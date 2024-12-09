#include <iostream>
using namespace std;

class Example {
    char a;   // 1 byte
    // Padding of 3 bytes to align `b` on a 4-byte boundary
    int b;    // 4 bytes
    char c;   // 1 byte
    // Padding of 3 bytes to make the class size a multiple of 4
};

int main() {
    Example ex;
    cout << "Size of class Example: " << sizeof(ex) << " bytes" << endl;
    return 0;
}

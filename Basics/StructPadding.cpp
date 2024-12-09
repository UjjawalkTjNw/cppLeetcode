#include <iostream>
using namespace std;

struct Example {
    char a;   // 1 byte
    // 3 bytes padding to align 'b' at a 4-byte boundary
    int b;    // 4 bytes
    char c;   // 1 byte
    // 3 bytes padding to make the struct's total size a multiple of 4
};

int main() {
    Example ex;
    cout << "Size of struct Example: " << sizeof(ex) << " bytes" << endl;
    return 0;
}

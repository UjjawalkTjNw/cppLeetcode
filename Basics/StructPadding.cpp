
//Example 1: Normal data type
/*
|1 byte a | 3 byte padding | 4 byte b | 1 byte c
*/

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





//Example2: with arrays
/*
| 10byte arr1 | 2 byte padding | 40 byte arr2

*/
#include <iostream>
using namespace std;

struct Example {
    char arr1[10]; // 10 bytes
    int arr2[10];  // 40 bytes
};

int main() {
    Example ex;
    cout << "Size of struct Example: " << sizeof(ex) << " bytes" << endl;
    return 0;
}


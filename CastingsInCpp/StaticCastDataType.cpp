#include <iostream>
using namespace std;

int main() {
    int intVar = 42;
    float floatVar = static_cast<float>(intVar);  // Convert int to float

    cout << "Integer: " << intVar << endl;
    cout << "Float: " << floatVar << endl;  // Output: 42.0

    return 0;
}

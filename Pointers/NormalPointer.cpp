#include <iostream>

void normalPointerExample() {
    int* ptr = new int(10); // Allocate memory
    std::cout << "Normal Pointer: " << *ptr << std::endl;
    delete ptr; // Deallocate memory
}

int main() {
    normalPointerExample();
    return 0;
}

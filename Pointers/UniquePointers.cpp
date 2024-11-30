//code 1:
#include <iostream>
#include <memory> // Include memory header for smart pointers

void smartPointerExample() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10); // Allocate memory
    std::cout << "Smart Pointer: " << *ptr << std::endl;
    // No need to manually delete, memory is automatically deallocated
}

int main() {
    smartPointerExample();
    return 0;
}



// Code2:
#include <iostream>
#include <memory>

void uniquePtrExample() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << "Unique Pointer: " << *ptr << std::endl;
    // No need to manually delete, memory is automatically managed
}

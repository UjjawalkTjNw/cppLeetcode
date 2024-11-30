//Shared pointer normal code:
#include <iostream>
#include <memory>

void sharedPtrExample() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);
    {
        std::shared_ptr<int> ptr2 = ptr1; // Shared ownership
        std::cout << "Shared Pointer 2: " << *ptr2 << std::endl;
    } // ptr2 goes out of scope but ptr1 still owns the object
    std::cout << "Shared Pointer 1: " << *ptr1 << std::endl;
}


//Shared Pointer with "Cyclic reference" issue:
#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    // Memory leak occurs here because of circular reference
    return 0;
}

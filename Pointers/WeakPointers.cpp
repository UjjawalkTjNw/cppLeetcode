//Weak pointers normal code:
#include <iostream>
#include <memory>

void weakPtrExample() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(30);
    std::weak_ptr<int> weakPtr = sharedPtr; // Weak reference

    if (auto ptr = weakPtr.lock()) { // Convert weak_ptr to shared_ptr
        std::cout << "Weak Pointer: " << *ptr << std::endl;
    } else {
        std::cout << "Weak Pointer is expired" << std::endl;
    }
}


//Weak pointers solving "Cyclic reference" issue in shared pointers
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
    std::weak_ptr<A> a_ptr; // Use weak_ptr to break the cycle
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    // Now, no memory leak because weak_ptr does not affect reference count
    return 0;
}

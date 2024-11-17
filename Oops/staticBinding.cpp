#include <iostream> // Include necessary header for input/output

class A {
public:
    void func() {
        std::cout << "A::func()" << std::endl; // Using std:: prefix
    }
};

class B : public A {
public:
    void func() {
        std::cout << "B::func()" << std::endl; // Using std:: prefix
    }
};

int main() {
    B objB;
    A* ptrA = &objB; // Pointer to A, pointing to an object of type B

    ptrA->func(); // Calls A::func()
}
//static binding: doesnot uses virtual keyword but code compiles succcessfully
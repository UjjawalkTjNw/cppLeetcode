#include <iostream> // Include necessary header for input/output

class A {
public:
    virtual void func() {
        std::cout << "A::func()" << std::endl; // Using std:: prefix
    }
};

class B : public A {
public:
    void func() override{
        std::cout << "B::func()" << std::endl; // Using std:: prefix
    }
};

int main() {
    B objB;
    A* ptrA = &objB; // Pointer to A, pointing to an object of type B

    ptrA->func(); // Calls B::func()
}

//In dynamic binding virtual keyword is used

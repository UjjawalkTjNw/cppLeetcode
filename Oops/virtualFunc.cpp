#include <iostream>

using namespace std;

class Base {
public:
    virtual void print() {
        cout << "Base class print() called" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "Derived class print() called" << endl;
    }
};

int main() {
    Base *basePtr;
    Derived derivedObj;

    // Base pointer pointing to a Derived object
    basePtr = &derivedObj;

    // Calling the print() function through the base pointer
    basePtr->print(); // Output: Derived class print() called

    return 0;
}
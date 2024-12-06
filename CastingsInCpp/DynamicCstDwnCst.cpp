#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class\n"; }
};

class AnotherClass : public Base {};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->show();  // Output: Derived class
    } else {
        cout << "Conversion failed\n";
    }

    basePtr = new AnotherClass();
    derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->show();
    } else {
        cout << "Conversion failed\n";  // Output: Conversion failed
    }

    delete basePtr; // Clean up
    return 0;
}

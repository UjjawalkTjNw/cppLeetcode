#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class\n"; }
};

int main() {
    //Case1: valid casting/conversion
    
    Base* basePtr = new Derived();
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->show();  // Output: Derived class.
    //i.e accessing show using derived ptr prints op of derived class so this casting is valid


    //case2: Invalid casting/conversion 
    Base* basePtr = new Base();
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->show();  // Output: Base class.
    //This case is invalid because we r accessing show func using derived ptr so expectation is that Derived class
    //comes as op but op come is Base class


    delete basePtr; // Clean up
    return 0;
}

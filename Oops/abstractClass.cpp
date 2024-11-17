#include <iostream>

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    // Shape shape; // Cannot create an object of an abstract class
    Circle circle;
    Square square;

    circle.draw();
    square.draw();

    return 0;
}

//even child class can be a abstract class:

class Base {
public:
    virtual void func1() {
        // Implementation for func1
    }
};

class Derived : public Base {
public:
    virtual void func2() = 0; // Pure virtual function in derived class
};
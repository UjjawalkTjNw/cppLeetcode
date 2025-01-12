#include <iostream>

// A simple function
void sayHello() {
    std::cout << "Hello!" << std::endl;
}

int main() {
    // Declare a function pointer
    void (*funcPtr)();

    // Assign the address of the function to the pointer
    funcPtr = sayHello;

    // Call the function using the pointer
    funcPtr();

    return 0;
}
//Op: hello



Ques2:

#include <iostream>
void increment(int& num) {
    num++;
}

int main() {
    void (*funcPtr)(int);
    int x = 5;
    funcPtr = increment;
    funcPtr(x);
    std::cout << x << std::endl;
    return 0;
}
This code gives error becos increment is accepting by ref i.e int&
but func pointer accepting by value i.e int
so it gives error
To correct write it like: void(*funcPtr)(int&)
























ques3:
#include <iostream>
int compute(int x) {
    return x * x;
}

int main() {
    int (*funcPtr)(int) = compute;
    std::cout << funcPtr(5) << std::endl;
    void* voidPtr = reinterpret_cast<void*>(funcPtr);
    funcPtr = reinterpret_cast<int (*)(int)>(voidPtr);
    std::cout << funcPtr(4) << std::endl;
    return 0;
}







ques4:
#include <iostream>
int add(int x, int y) {
    return x + y;
}

int main() {
    int (*funcPtr)(int, int) = nullptr;
    funcPtr = add;
    std::cout << (*funcPtr)(3, 7) << std::endl;
    funcPtr = reinterpret_cast<int (*)(int, int)>(0x1234);
    std::cout << funcPtr(1, 2) << std::endl;
    return 0;
}


ques5:
#include <iostream>
int square(int x) {
    return x * x;
}

int cube(int x) {
    return x * x * x;
}

int main() {
    int (*funcPtr)(int);
    funcPtr = square;
    std::cout << funcPtr(3) << std::endl;
    funcPtr = cube;
    std::cout << funcPtr(3) << std::endl;
    funcPtr = reinterpret_cast<int (*)(int)>(nullptr);
    std::cout << funcPtr(2) << std::endl; // What happens here?
    return 0;
}



ques6:
#include <iostream>
void saySomething(const char* msg) {
    std::cout << msg << std::endl;
}

int main() {
    void (*funcPtr)(const char*) = saySomething;
    funcPtr("C++ is fun!");
    funcPtr = reinterpret_cast<void (*)(const char*)>(0xDEADBEEF); // Analyze this
    funcPtr("What will happen?");
    return 0;
}


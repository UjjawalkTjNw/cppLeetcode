#include <iostream>
#include <cassert>

int divide(int numerator, int denominator) {
    assert(denominator != 0 && "Denominator should not be zero"); // Assertion to check denominator
    return numerator / denominator;
}

int main() {
    int a = 10;
    int b = 2;
    int result = divide(a, b);
    std::cout << "Result: " << result << std::endl;

    b = 0;
    result = divide(a, b); // This will trigger the assert
    std::cout << "Result: " << result << std::endl;

    return 0;
}

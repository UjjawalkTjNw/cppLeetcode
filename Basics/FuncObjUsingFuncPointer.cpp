#include <iostream>

// A function that takes a callback as a parameter
void executeCallback(void (*callback)(int)) {
    int value = 42; // Example value
    callback(value); // Call the passed-in function
}

// A sample callback function
void printValue(int value) {
    std::cout << "The value is: " << value << std::endl;
}

int main() {
    // Pass the callback function to the executeCallback function
    executeCallback(printValue);
    return 0;
}
